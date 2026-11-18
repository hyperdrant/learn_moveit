"""
RoArm-M2 驱动节点

    Arm Driver Node
    ├── Topic       /joint_states        持续发布当前关节角
    ├── Service     /home_arm            (std_srvs/Trigger) 回到初始位姿
    │               /set_gripper         (std_srvs/SetBool) true=张开 false=夹紧
    ├── Action      /move_joints         (roarm_interfaces/MoveJoints) 带进度反馈的关节运动
    └── Parameters  sim, port, baudrate          启动时决定，运行中只读
                    default_speed, goal_tolerance, settle_timeout, sim_max_velocity
                                                 运行中可以 ros2 param set 修改

    ros2 run roarm_driver driver                         # 模拟模式
    ros2 run roarm_driver driver --ros-args -p sim:=false -p port:=/dev/ttyUSB0
"""
import threading
import time

import rclpy
from rcl_interfaces.msg import ParameterDescriptor, SetParametersResult
from rclpy.action import ActionServer, CancelResponse, GoalResponse
from rclpy.callback_groups import ReentrantCallbackGroup
from rclpy.executors import ExternalShutdownException, MultiThreadedExecutor
from rclpy.node import Node
from sensor_msgs.msg import JointState
from std_srvs.srv import SetBool, Trigger

from roarm_driver.backends import (GRIPPER_CLOSE, GRIPPER_OPEN, JOINT_LIMITS,
                                   JOINT_NAMES, SerialBackend, SimBackend)
from roarm_interfaces.action import MoveJoints

CONTROL_RATE = 20.0  # 执行 Action 时发送插值目标的频率 (Hz)


class RoArmDriver(Node):

    def __init__(self):
        super().__init__('roarm_driver')

        # ---------- Parameters ----------
        read_only = ParameterDescriptor(read_only=True)
        self.declare_parameter('sim', True, read_only)
        self.declare_parameter('port', '/dev/ttyUSB0', read_only)
        self.declare_parameter('baudrate', 115200, read_only)
        self.declare_parameter('publish_rate', 20.0, read_only)
        self.declare_parameter('default_speed', 0.8)      # rad/s，duration<=0 时用
        self.declare_parameter('goal_tolerance', 0.02)    # rad
        self.declare_parameter('settle_timeout', 2.0)     # s，插值结束后最多等多久到位
        self.declare_parameter('sim_max_velocity', 1.5)   # rad/s，模拟电机的最大速度
        # 运行中有人 ros2 param set 时会先调用它，返回 successful=False 就拒绝修改
        self.add_on_set_parameters_callback(self.on_set_parameters)

        if self.get_parameter('sim').value:
            self.backend = SimBackend(self.get_parameter('sim_max_velocity').value)
            self.get_logger().info('模拟模式：没有连接真机')
        else:
            port = self.get_parameter('port').value
            self.backend = SerialBackend(
                port, self.get_parameter('baudrate').value, self.get_logger())
            self.get_logger().info(f'真机模式：串口 {port}')

        # 同一时间只允许一个运动（Action 或回零）
        self._busy_lock = threading.Lock()
        self._busy = False

        # Action 的 execute 回调会循环好几秒，必须和 joint_states 定时器并行跑，
        # 所以用 ReentrantCallbackGroup + MultiThreadedExecutor（见 main）
        cb_group = ReentrantCallbackGroup()

        # ---------- Topic ----------
        self.js_pub = self.create_publisher(JointState, 'joint_states', 10)
        self.create_timer(1.0 / self.get_parameter('publish_rate').value,
                          self.publish_joint_states, callback_group=cb_group)

        # ---------- Service ----------
        self.create_service(Trigger, 'home_arm', self.on_home,
                            callback_group=cb_group)
        self.create_service(SetBool, 'set_gripper', self.on_set_gripper,
                            callback_group=cb_group)

        # ---------- Action ----------
        self.action_server = ActionServer(
            self, MoveJoints, 'move_joints',
            execute_callback=self.execute_move,
            goal_callback=self.on_goal,
            cancel_callback=self.on_cancel,
            callback_group=cb_group)

    # ======================================================================
    # Parameters
    # ======================================================================

    def on_set_parameters(self, params):
        for p in params:
            if p.name in ('default_speed', 'goal_tolerance', 'settle_timeout',
                          'sim_max_velocity') and p.value <= 0:
                return SetParametersResult(
                    successful=False, reason=f'{p.name} 必须 > 0')
            if p.name == 'sim_max_velocity' and isinstance(self.backend, SimBackend):
                self.backend.max_velocity = p.value
        return SetParametersResult(successful=True)

    # ======================================================================
    # Topic
    # ======================================================================

    def publish_joint_states(self):
        q = self.backend.read()
        if q is None:  # 真机还没回反馈
            return
        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.name = JOINT_NAMES
        msg.position = q
        self.js_pub.publish(msg)

    # ======================================================================
    # Service：请求 → 执行一次 → 立即返回结果
    # ======================================================================

    def _try_acquire(self):
        with self._busy_lock:
            if self._busy:
                return False
            self._busy = True
            return True

    def _release(self):
        with self._busy_lock:
            self._busy = False

    def on_home(self, request, response):
        if not self._try_acquire():
            response.success = False
            response.message = '正在执行运动，拒绝回零'
            return response
        try:
            self.backend.home()
        finally:
            self._release()
        # 注意：这里只是"命令已发出"，不等机械臂真的到位。
        # 想要知道进度和是否到位，就该用 Action —— 这正是两者的区别。
        response.success = True
        response.message = '回零命令已发送'
        self.get_logger().info(response.message)
        return response

    def on_set_gripper(self, request, response):
        q = self.backend.read()
        if q is None:
            response.success = False
            response.message = '还没有收到关节反馈'
            return response
        q[3] = GRIPPER_OPEN if request.data else GRIPPER_CLOSE
        self.backend.command(q)
        response.success = True
        response.message = '夹爪张开' if request.data else '夹爪夹紧'
        self.get_logger().info(response.message)
        return response

    # ======================================================================
    # Action：Goal → Feedback, Feedback, ... → Result
    # ======================================================================

    def on_goal(self, goal):
        """收到新 goal 时先在这里决定接受还是拒绝，还没开始执行"""
        names, pos = list(goal.joint_names), list(goal.positions)
        if not names or len(names) != len(pos):
            self.get_logger().warn('拒绝：joint_names 和 positions 长度不一致或为空')
            return GoalResponse.REJECT
        for n, p in zip(names, pos):
            if n not in JOINT_NAMES:
                self.get_logger().warn(f'拒绝：未知关节 {n}')
                return GoalResponse.REJECT
            lo, hi = JOINT_LIMITS[JOINT_NAMES.index(n)]
            if not lo <= p <= hi:
                self.get_logger().warn(
                    f'拒绝：{n} = {p:.3f} 超出限位 [{lo:.3f}, {hi:.3f}]')
                return GoalResponse.REJECT
        if not self._try_acquire():
            self.get_logger().warn('拒绝：上一个运动还没结束')
            return GoalResponse.REJECT
        return GoalResponse.ACCEPT

    def on_cancel(self, goal_handle):
        self.get_logger().info('收到取消请求')
        return CancelResponse.ACCEPT

    def execute_move(self, goal_handle):
        try:
            return self._execute_move(goal_handle)
        finally:
            self._release()

    def _execute_move(self, goal_handle):
        goal = goal_handle.request
        idx = [JOINT_NAMES.index(n) for n in goal.joint_names]
        result = MoveJoints.Result()

        start = self.backend.read()
        if start is None:
            goal_handle.abort()
            result.message = '还没有收到关节反馈'
            return result

        # 没在 goal 里出现的关节保持当前角度
        target = list(start)
        for i, p in zip(idx, goal.positions):
            target[i] = p

        duration = goal.duration
        if duration <= 0:
            dist = max(abs(t - s) for t, s in zip(target, start))
            duration = max(dist / self.get_parameter('default_speed').value, 0.2)
        self.get_logger().info(f'开始运动，预计 {duration:.2f} s')

        def make_result(success, message):
            q = self.backend.read()
            result.success = success
            result.message = message
            result.final_positions = [q[i] for i in idx]
            result.max_error = max(abs(q[i] - target[i]) for i in idx)
            return result

        # ---- 阶段 1：按时间插值，持续发送中间目标 + feedback ----
        feedback = MoveJoints.Feedback()
        t0 = time.monotonic()
        while True:
            if goal_handle.is_cancel_requested:
                self.backend.command(self.backend.read())  # 停在当前位置
                goal_handle.canceled()
                self.get_logger().info('运动已取消')
                return make_result(False, '已取消')

            s = min((time.monotonic() - t0) / duration, 1.0)
            # smoothstep：起点和终点速度为 0，比直线插值更平稳
            k = s * s * (3 - 2 * s)
            self.backend.command([a + (b - a) * k for a, b in zip(start, target)])

            q = self.backend.read()
            feedback.current_positions = [q[i] for i in idx]
            feedback.progress = s
            goal_handle.publish_feedback(feedback)

            if s >= 1.0:
                break
            time.sleep(1.0 / CONTROL_RATE)

        # ---- 阶段 2：命令发完了，等实际角度真正到位 ----
        tol = self.get_parameter('goal_tolerance').value
        deadline = time.monotonic() + self.get_parameter('settle_timeout').value
        while time.monotonic() < deadline:
            q = self.backend.read()
            if max(abs(q[i] - target[i]) for i in idx) < tol:
                goal_handle.succeed()
                self.get_logger().info('运动完成')
                return make_result(True, '到达目标')
            time.sleep(1.0 / CONTROL_RATE)

        goal_handle.abort()
        self.get_logger().warn('运动超时，未到达目标')
        return make_result(False, f'超时：{self.get_parameter("settle_timeout").value} s 内未进入容差')

    def destroy_node(self):
        self.backend.close()
        super().destroy_node()


def main():
    rclpy.init()
    node = RoArmDriver()
    executor = MultiThreadedExecutor()
    executor.add_node(node)
    try:
        executor.spin()
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
