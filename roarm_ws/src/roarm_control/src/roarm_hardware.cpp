#include "roarm_control/roarm_hardware.hpp"

#include <fcntl.h>
#include <sys/ioctl.h>
#include <termios.h>
#include <unistd.h>

#include <algorithm>
#include <chrono>
#include <cmath>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <thread>

#include "hardware_interface/types/hardware_interface_type_values.hpp"
#include "pluginlib/class_list_macros.hpp"

namespace roarm_control
{

using hardware_interface::CallbackReturn;
using hardware_interface::return_type;

// 固件 {"T":100} 初始位姿：base=0, shoulder=0, elbow=pi/2
static const std::vector<double> kHome = {0.0, 0.0, M_PI / 2};

// ============================================================================
// 生命周期
// ============================================================================

CallbackReturn RoArmHardware::on_init(const hardware_interface::HardwareInfo & info)
{
  // 父类会把 info 存进 info_，里面就是 URDF <ros2_control> 标签的内容
  if (SystemInterface::on_init(info) != CallbackReturn::SUCCESS) {
    return CallbackReturn::ERROR;
  }

  auto get = [&](const std::string & key, const std::string & def) {
      auto it = info_.hardware_parameters.find(key);
      return it == info_.hardware_parameters.end() ? def : it->second;
    };
  sim_ = get("sim", "true") == "true";
  sim_max_velocity_ = std::stod(get("sim_max_velocity", "1.5"));
  port_ = get("port", "/dev/ttyUSB0");
  baudrate_ = std::stoi(get("baudrate", "115200"));
  feedback_rate_ = std::stod(get("feedback_rate", "20.0"));

  // 检查 URDF 里的配置是不是我们支持的：3 个关节，每个关节
  // 1 个 position command interface，state interface 为 position (+ velocity)
  if (info_.joints.size() != 3) {
    RCLCPP_FATAL(logger_, "需要 3 个关节（base, shoulder, elbow），URDF 里有 %zu 个",
      info_.joints.size());
    return CallbackReturn::ERROR;
  }
  for (const auto & joint : info_.joints) {
    if (joint.command_interfaces.size() != 1 ||
      joint.command_interfaces[0].name != hardware_interface::HW_IF_POSITION)
    {
      RCLCPP_FATAL(logger_, "关节 %s 必须只有一个 position command interface",
        joint.name.c_str());
      return CallbackReturn::ERROR;
    }
  }

  hw_commands_.assign(3, std::nan(""));
  hw_velocities_.assign(3, 0.0);
  hw_states_ = kHome;
  // URDF 里可以用 <param name="initial_value"> 覆盖初始角度（只在模拟模式有意义）
  for (size_t i = 0; i < 3; ++i) {
    const auto & init = info_.joints[i].state_interfaces[0].initial_value;
    if (!init.empty()) {
      hw_states_[i] = std::stod(init);
    }
  }

  RCLCPP_INFO(logger_, "on_init 完成：%s 模式", sim_ ? "模拟" : "真机");
  return CallbackReturn::SUCCESS;
}

CallbackReturn RoArmHardware::on_configure(const rclcpp_lifecycle::State &)
{
  // configure 阶段：建立和硬件的连接，但还不让它动
  if (!sim_ && !open_serial()) {
    return CallbackReturn::ERROR;
  }
  return CallbackReturn::SUCCESS;
}

CallbackReturn RoArmHardware::on_activate(const rclcpp_lifecycle::State &)
{
  if (!sim_) {
    // 等待第一次关节反馈，最多 3 秒
    got_feedback_ = false;
    for (int i = 0; i < 60 && !got_feedback_; ++i) {
      send_line("{\"T\":105}");
      std::this_thread::sleep_for(std::chrono::milliseconds(50));
      poll_serial();
    }
    if (!got_feedback_) {
      RCLCPP_FATAL(logger_, "3 秒内没收到机械臂反馈，检查串口和电源");
      return CallbackReturn::ERROR;
    }
    for (size_t i = 0; i < 3; ++i) {
      hw_states_[i] = fb_positions_[i];
    }
    last_sent_.clear();
  }

  // 非常重要：激活时让 command = 当前 state，否则机械臂会猛地跳向一个旧的/默认的命令
  hw_commands_ = hw_states_;
  RCLCPP_INFO(logger_, "已激活，当前关节角 [%.3f, %.3f, %.3f]",
    hw_states_[0], hw_states_[1], hw_states_[2]);
  return CallbackReturn::SUCCESS;
}

CallbackReturn RoArmHardware::on_deactivate(const rclcpp_lifecycle::State &)
{
  RCLCPP_INFO(logger_, "已停用");
  return CallbackReturn::SUCCESS;
}

CallbackReturn RoArmHardware::on_cleanup(const rclcpp_lifecycle::State &)
{
  close_serial();
  return CallbackReturn::SUCCESS;
}

// ============================================================================
// 导出 interface：把成员变量的地址交给 controller_manager
// ============================================================================

std::vector<hardware_interface::StateInterface> RoArmHardware::export_state_interfaces()
{
  std::vector<hardware_interface::StateInterface> interfaces;
  for (size_t i = 0; i < info_.joints.size(); ++i) {
    // 例如 "shoulder_joint/position" → &hw_states_[1]
    interfaces.emplace_back(
      info_.joints[i].name, hardware_interface::HW_IF_POSITION, &hw_states_[i]);
    interfaces.emplace_back(
      info_.joints[i].name, hardware_interface::HW_IF_VELOCITY, &hw_velocities_[i]);
  }
  return interfaces;
}

std::vector<hardware_interface::CommandInterface> RoArmHardware::export_command_interfaces()
{
  std::vector<hardware_interface::CommandInterface> interfaces;
  for (size_t i = 0; i < info_.joints.size(); ++i) {
    interfaces.emplace_back(
      info_.joints[i].name, hardware_interface::HW_IF_POSITION, &hw_commands_[i]);
  }
  return interfaces;
}

// ============================================================================
// read / write：每个控制周期调用一次，必须快，不能阻塞
// ============================================================================

return_type RoArmHardware::read(const rclcpp::Time &, const rclcpp::Duration & period)
{
  const double dt = period.seconds();
  const std::vector<double> prev = hw_states_;

  if (sim_) {
    // 模拟电机：以不超过 sim_max_velocity 的速度追向命令
    const double step = sim_max_velocity_ * dt;
    for (size_t i = 0; i < 3; ++i) {
      if (std::isnan(hw_commands_[i])) {
        continue;
      }
      hw_states_[i] += std::clamp(hw_commands_[i] - hw_states_[i], -step, step);
    }
  } else {
    // 按 feedback_rate 请求反馈；回复是异步到达的，poll_serial 收到就更新 fb_positions_
    const auto now = std::chrono::steady_clock::now();
    if (std::chrono::duration<double>(now - last_feedback_request_).count() >=
      1.0 / feedback_rate_)
    {
      send_line("{\"T\":105}");
      last_feedback_request_ = now;
    }
    poll_serial();
    for (size_t i = 0; i < 3; ++i) {
      hw_states_[i] = fb_positions_[i];
    }
  }

  if (dt > 0) {
    for (size_t i = 0; i < 3; ++i) {
      hw_velocities_[i] = (hw_states_[i] - prev[i]) / dt;
    }
  }
  return return_type::OK;
}

return_type RoArmHardware::write(const rclcpp::Time &, const rclcpp::Duration &)
{
  if (sim_) {
    return return_type::OK;  // 模拟模式在 read() 里推进状态
  }
  for (double c : hw_commands_) {
    if (std::isnan(c)) {
      return return_type::OK;  // controller 还没给出命令
    }
  }

  // 命令没变就不发，节省串口带宽（115200 波特率大约只有 11 KB/s）
  bool changed = last_sent_.size() != 3;
  for (size_t i = 0; !changed && i < 3; ++i) {
    changed = std::abs(hw_commands_[i] - last_sent_[i]) > 1e-4;
  }
  if (!changed) {
    return return_type::OK;
  }

  char buf[160];
  std::snprintf(buf, sizeof(buf),
    "{\"T\":102,\"base\":%.4f,\"shoulder\":%.4f,\"elbow\":%.4f,\"hand\":%.4f,"
    "\"spd\":0,\"acc\":10}",
    hw_commands_[0], hw_commands_[1], hw_commands_[2], hand_);
  send_line(buf);
  last_sent_ = hw_commands_;
  return return_type::OK;
}

// ============================================================================
// 串口
// ============================================================================

bool RoArmHardware::open_serial()
{
  fd_ = ::open(port_.c_str(), O_RDWR | O_NOCTTY | O_NONBLOCK);
  if (fd_ < 0) {
    RCLCPP_FATAL(logger_, "打不开串口 %s（检查设备是否存在、用户是否在 dialout 组）",
      port_.c_str());
    return false;
  }

  termios tty{};
  tcgetattr(fd_, &tty);
  cfmakeraw(&tty);
  speed_t speed = B115200;
  if (baudrate_ == 9600) {speed = B9600;} else if (baudrate_ == 57600) {speed = B57600;}
  cfsetispeed(&tty, speed);
  cfsetospeed(&tty, speed);
  tty.c_cflag |= (CLOCAL | CREAD);
  tcsetattr(fd_, TCSANOW, &tty);

  // 和官方 serial_simple_ctrl.py 一样拉低 RTS/DTR，避免 ESP32 被复位
  int bits = TIOCM_RTS | TIOCM_DTR;
  ioctl(fd_, TIOCMBIC, &bits);
  tcflush(fd_, TCIOFLUSH);

  fb_positions_ = kHome;
  RCLCPP_INFO(logger_, "已打开串口 %s @ %d", port_.c_str(), baudrate_);
  return true;
}

void RoArmHardware::close_serial()
{
  if (fd_ >= 0) {
    ::close(fd_);
    fd_ = -1;
  }
}

void RoArmHardware::send_line(const std::string & line)
{
  if (fd_ < 0) {
    return;
  }
  const std::string data = line + "\n";
  if (::write(fd_, data.data(), data.size()) < 0) {
    RCLCPP_WARN_THROTTLE(logger_, *rclcpp::Clock::make_shared(), 2000, "串口写入失败");
  }
}

void RoArmHardware::poll_serial()
{
  char buf[512];
  ssize_t n;
  while ((n = ::read(fd_, buf, sizeof(buf))) > 0) {
    rx_buffer_.append(buf, n);
  }
  size_t pos;
  while ((pos = rx_buffer_.find('\n')) != std::string::npos) {
    parse_feedback(rx_buffer_.substr(0, pos));
    rx_buffer_.erase(0, pos + 1);
  }
  if (rx_buffer_.size() > 4096) {
    rx_buffer_.clear();  // 防止乱码导致缓冲区无限增长
  }
}

bool RoArmHardware::parse_feedback(const std::string & line)
{
  // 固件回复示例：{"T":1051,"x":..,"y":..,"z":..,"b":0.0,"s":0.0,"e":1.57,"t":3.14,"torB":..}
  // 只需要 b/s/e/t 四个字段，这里手写一个最简单的解析，不引入 JSON 库
  if (line.find("\"T\":1051") == std::string::npos) {
    return false;
  }
  auto field = [&](const char * key, double & out) {
      auto p = line.find(key);
      if (p == std::string::npos) {
        return false;
      }
      out = std::strtod(line.c_str() + p + std::strlen(key), nullptr);
      return true;
    };
  double b, s, e, t;
  if (!field("\"b\":", b) || !field("\"s\":", s) || !field("\"e\":", e)) {
    return false;
  }
  fb_positions_ = {b, s, e};
  if (field("\"t\":", t) && !got_feedback_) {
    hand_ = t;  // 只在第一次反馈时记下夹爪角度
  }
  got_feedback_ = true;
  return true;
}

}  // namespace roarm_control

// 把这个类注册成 pluginlib 插件，controller_manager 根据 URDF 里的
// <plugin>roarm_control/RoArmHardware</plugin> 找到并加载它
PLUGINLIB_EXPORT_CLASS(roarm_control::RoArmHardware, hardware_interface::SystemInterface)
