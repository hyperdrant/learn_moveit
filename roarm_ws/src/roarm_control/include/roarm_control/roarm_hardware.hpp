// RoArm-M2 的 ros2_control 硬件接口（Hardware Interface）
//
//   controller_manager 每个周期（update_rate，例如 50Hz）依次调用：
//
//     read()   机械臂 → hw_states_     （当前关节角）
//     各个 controller 的 update()        （读 state，算出新的 command）
//     write()  hw_commands_ → 机械臂   （目标关节角）
//
//   controller 只通过 state/command interface（其实就是指向 hw_states_ / hw_commands_
//   的指针）和硬件打交道，完全不知道背后是串口、CAN 还是模拟器。
//
// 两种模式（URDF <ros2_control> 里的 <param name="sim">）：
//   sim=true ：内存模拟，关节以不超过 sim_max_velocity 的速度追向命令
//   sim=false：通过串口和 RoArm-M2 固件通信（JSON 命令，见固件 json_cmd.h）

#ifndef ROARM_CONTROL__ROARM_HARDWARE_HPP_
#define ROARM_CONTROL__ROARM_HARDWARE_HPP_

#include <chrono>
#include <string>
#include <vector>

#include "hardware_interface/handle.hpp"
#include "hardware_interface/hardware_info.hpp"
#include "hardware_interface/system_interface.hpp"
#include "hardware_interface/types/hardware_interface_return_values.hpp"
#include "rclcpp/rclcpp.hpp"
#include "rclcpp_lifecycle/state.hpp"

namespace roarm_control
{

class RoArmHardware : public hardware_interface::SystemInterface
{
public:
  // 生命周期：on_init → on_configure → on_activate → (read/write 循环) → on_deactivate
  hardware_interface::CallbackReturn on_init(
    const hardware_interface::HardwareInfo & info) override;

  hardware_interface::CallbackReturn on_configure(
    const rclcpp_lifecycle::State & previous_state) override;

  hardware_interface::CallbackReturn on_activate(
    const rclcpp_lifecycle::State & previous_state) override;

  hardware_interface::CallbackReturn on_deactivate(
    const rclcpp_lifecycle::State & previous_state) override;

  hardware_interface::CallbackReturn on_cleanup(
    const rclcpp_lifecycle::State & previous_state) override;

  // 告诉 controller_manager：我有哪些 state / command interface
  std::vector<hardware_interface::StateInterface> export_state_interfaces() override;
  std::vector<hardware_interface::CommandInterface> export_command_interfaces() override;

  hardware_interface::return_type read(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

  hardware_interface::return_type write(
    const rclcpp::Time & time, const rclcpp::Duration & period) override;

private:
  // ---- 串口 ----
  bool open_serial();
  void close_serial();
  void send_line(const std::string & line);
  void poll_serial();                      // 非阻塞地读串口，解析完整的行
  bool parse_feedback(const std::string & line);

  rclcpp::Logger logger_ = rclcpp::get_logger("RoArmHardware");

  // 参数（来自 URDF <ros2_control><hardware><param>）
  bool sim_ = true;
  double sim_max_velocity_ = 1.5;  // rad/s
  std::string port_ = "/dev/ttyUSB0";
  int baudrate_ = 115200;
  double feedback_rate_ = 20.0;    // 真机：每秒请求几次 {"T":105}

  // 每个关节一个元素，顺序同 URDF 里 <joint> 的顺序
  std::vector<double> hw_commands_;
  std::vector<double> hw_states_;
  std::vector<double> hw_velocities_;

  // 真机相关
  int fd_ = -1;
  std::string rx_buffer_;
  bool got_feedback_ = false;
  std::vector<double> fb_positions_;     // 最近一次串口反馈的关节角
  double hand_ = 3.14159;                 // 夹爪不归 ros2_control 管，保持激活时的值
  std::vector<double> last_sent_;
  std::chrono::steady_clock::time_point last_feedback_request_{};
};

}  // namespace roarm_control

#endif  // ROARM_CONTROL__ROARM_HARDWARE_HPP_
