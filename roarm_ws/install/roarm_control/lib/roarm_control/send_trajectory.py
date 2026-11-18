#!/usr/bin/env python3
"""
向 arm_controller (JointTrajectoryController) 发送一条多点轨迹

轨迹（角度，单位度）：
    t=0   起点（当前位置，JTC 自动处理）
    t=1   [ 30,  10,  80]
    t=2   [ 60,  20,  60]
    t=3   [ 30,  30,  90]
    t=4   [  0,   0,  90]   回到初始位姿

    ros2 run roarm_control send_trajectory.py
    ros2 run roarm_control send_trajectory.py --scale 0.5   # 时间缩短一半，跑得更快
"""
import argparse
import math

import rclpy
from builtin_interfaces.msg import Duration
from control_msgs.action import FollowJointTrajectory
from rclpy.action import ActionClient
from rclpy.node import Node
from trajectory_msgs.msg import JointTrajectoryPoint

JOINTS = ['base_joint', 'shoulder_joint', 'elbow_joint']

# (到达时间 s, [base, shoulder, elbow] 度)
WAYPOINTS = [
    (1.0, [30, 10, 80]),
    (2.0, [60, 20, 60]),
    (3.0, [30, 30, 90]),
    (4.0, [0, 0, 90]),
]


def to_duration(t):
    return Duration(sec=int(t), nanosec=int((t - int(t)) * 1e9))


class TrajectoryClient(Node):

    def __init__(self):
        super().__init__('send_trajectory')
        self.client = ActionClient(
            self, FollowJointTrajectory, '/arm_controller/follow_joint_trajectory')
        self._last_print = -1.0

    def run(self, scale):
        goal = FollowJointTrajectory.Goal()
        goal.trajectory.joint_names = JOINTS
        for t, deg in WAYPOINTS:
            p = JointTrajectoryPoint()
            p.positions = [math.radians(d) for d in deg]
            # 只给 positions、不给 velocities：JTC 用样条自己算中间的速度
            p.time_from_start = to_duration(t * scale)
            goal.trajectory.points.append(p)

        self.get_logger().info('等待 arm_controller ...')
        self.client.wait_for_server()
        self.get_logger().info(f'发送 {len(WAYPOINTS)} 个轨迹点，总时长 {WAYPOINTS[-1][0] * scale:.1f} s')

        f = self.client.send_goal_async(goal, feedback_callback=self.on_feedback)
        rclpy.spin_until_future_complete(self, f)
        handle = f.result()
        if not handle.accepted:
            self.get_logger().error('轨迹被拒绝')
            return

        f = handle.get_result_async()
        rclpy.spin_until_future_complete(self, f)
        res = f.result().result
        # error_code 0 = SUCCESSFUL，负数是各种失败（见 FollowJointTrajectory.action）
        self.get_logger().info(
            f'完成: error_code={res.error_code} {res.error_string or "(SUCCESSFUL)"}')

    def on_feedback(self, msg):
        fb = msg.feedback
        t = fb.desired.time_from_start.sec + fb.desired.time_from_start.nanosec * 1e-9
        if t - self._last_print < 0.25:  # JTC 每个周期都发 feedback，这里限流打印
            return
        self._last_print = t
        des = ' '.join(f'{math.degrees(p):6.1f}' for p in fb.desired.positions)
        act = ' '.join(f'{math.degrees(p):6.1f}' for p in fb.actual.positions)
        err = max(abs(math.degrees(e)) for e in fb.error.positions)
        self.get_logger().info(f't={t:4.2f}s  期望[{des}]  实际[{act}]  误差 {err:4.2f}°')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('--scale', type=float, default=1.0, help='时间缩放系数')
    args, ros_args = parser.parse_known_args()

    rclpy.init(args=ros_args)
    node = TrajectoryClient()
    try:
        node.run(args.scale)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
