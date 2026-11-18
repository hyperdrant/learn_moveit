"""
Action Client 示例：发送 MoveJoints goal，打印 feedback 和 result

角度单位是度，按 base shoulder elbow [hand] 的顺序给：
    ros2 run roarm_driver move_client 30 20 60
    ros2 run roarm_driver move_client 30 20 60 --duration 3
    ros2 run roarm_driver move_client -30 0 90 --cancel-after 1.0   # 1 秒后取消
"""
import argparse
import math

import rclpy
from rclpy.action import ActionClient
from rclpy.node import Node

from roarm_interfaces.action import MoveJoints

JOINTS = ['base_joint', 'shoulder_joint', 'elbow_joint', 'hand_joint']


class MoveClient(Node):

    def __init__(self):
        super().__init__('move_client')
        self.client = ActionClient(self, MoveJoints, 'move_joints')

    def send(self, degrees, duration, cancel_after):
        goal = MoveJoints.Goal()
        goal.joint_names = JOINTS[:len(degrees)]
        goal.positions = [math.radians(d) for d in degrees]
        goal.duration = duration

        self.get_logger().info('等待 action server ...')
        self.client.wait_for_server()

        # ① 发送 goal（异步），并注册 feedback 回调
        send_future = self.client.send_goal_async(
            goal, feedback_callback=self.on_feedback)
        rclpy.spin_until_future_complete(self, send_future)
        goal_handle = send_future.result()

        # ② server 可能拒绝（超限位、正忙……）
        if not goal_handle.accepted:
            self.get_logger().error('goal 被拒绝，看 driver 的日志找原因')
            return
        self.get_logger().info('goal 已接受')

        # ③ 可选：过一段时间后取消
        if cancel_after > 0:
            self.create_timer(cancel_after, lambda: self.cancel(goal_handle))

        # ④ 等待 result（期间 feedback 回调会不断被调用）
        result_future = goal_handle.get_result_async()
        rclpy.spin_until_future_complete(self, result_future)
        r = result_future.result().result
        final = ', '.join(f'{math.degrees(p):.1f}°' for p in r.final_positions)
        self.get_logger().info(
            f'结果: success={r.success}  "{r.message}"\n'
            f'      final=[{final}]  max_error={math.degrees(r.max_error):.2f}°')

    def on_feedback(self, msg):
        fb = msg.feedback
        bar = '#' * int(fb.progress * 20)
        cur = ', '.join(f'{math.degrees(p):6.1f}°' for p in fb.current_positions)
        self.get_logger().info(f'[{bar:<20}] {fb.progress * 100:5.1f}%  [{cur}]')

    def cancel(self, goal_handle):
        self.get_logger().info('发送取消请求')
        goal_handle.cancel_goal_async()


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('degrees', type=float, nargs='+',
                        help='目标角度（度）：base shoulder elbow [hand]')
    parser.add_argument('--duration', type=float, default=0.0,
                        help='期望用时（秒），0 表示让驱动自己算')
    parser.add_argument('--cancel-after', type=float, default=0.0,
                        help='多少秒后取消，0 表示不取消')
    args, ros_args = parser.parse_known_args()
    if not 1 <= len(args.degrees) <= 4:
        parser.error('需要 1~4 个角度')

    rclpy.init(args=ros_args)
    node = MoveClient()
    try:
        node.send(args.degrees, args.duration, args.cancel_after)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
