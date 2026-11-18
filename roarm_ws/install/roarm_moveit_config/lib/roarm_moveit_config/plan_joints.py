#!/usr/bin/env python3
"""
Joint-space planning：给 MoveIt 一组目标关节角，让它规划并执行

角度单位是度，顺序 base shoulder elbow：
    ros2 run roarm_moveit_config plan_joints.py 60 30 60              # 规划并执行
    ros2 run roarm_moveit_config plan_joints.py 60 30 60 --plan-only  # 只规划，不动
    ros2 run roarm_moveit_config plan_joints.py 0 120 0               # 超出限位 → 客户端拒绝
    ros2 run roarm_moveit_config plan_joints.py --add-obstacle        # 在场景里放一个障碍物
    ros2 run roarm_moveit_config plan_joints.py --clear-obstacle

和 Week 3 send_trajectory.py 的区别：
    send_trajectory.py 自己写好每个轨迹点 → 直接发给 JTC
    plan_joints.py     只给"终点" → MoveIt 规划出中间所有点（避开限位和碰撞，满足速度/加速度）
                       → MoveIt 再把轨迹发给同一个 JTC
"""
import argparse
import math

import rclpy
from geometry_msgs.msg import Pose
from moveit_msgs.action import MoveGroup
from moveit_msgs.msg import (CollisionObject, Constraints, JointConstraint,
                             MoveItErrorCodes, PlanningScene)
from moveit_msgs.srv import ApplyPlanningScene
from rclpy.action import ActionClient
from rclpy.node import Node
from shape_msgs.msg import SolidPrimitive

JOINTS = ['base_joint', 'shoulder_joint', 'elbow_joint']

# 和 URDF <limit> 一致（度）。
# 注意：MoveIt 收到超出限位的 JointConstraint 时不会报错，而是打一条 WARN，
# 把目标截断到限位上继续规划执行（"Assuming maximum bounds instead"）。
# 机械臂会去一个你没要求的位置，所以在发请求前自己检查一遍。
LIMITS_DEG = [(-180.0, 180.0), (-90.0, 90.0), (-45.0, 180.0)]
OBSTACLE_ID = 'demo_box'

# MoveItErrorCodes 里数字 → 名字，方便打印
ERROR_NAMES = {v: k for k, v in vars(MoveItErrorCodes).items()
               if k.isupper() and isinstance(v, int)}


class JointPlanner(Node):

    def __init__(self):
        super().__init__('plan_joints')
        # move_group 节点提供的 action：规划（+ 可选执行）
        self.move_client = ActionClient(self, MoveGroup, '/move_action')
        # move_group 提供的 service：修改规划场景（添加/删除障碍物）
        self.scene_client = self.create_client(ApplyPlanningScene, '/apply_planning_scene')

    # ------------------------------------------------------------------
    # 规划
    # ------------------------------------------------------------------

    def plan(self, degrees, plan_only, velocity_scaling):
        for name, deg, (lo, hi) in zip(JOINTS, degrees, LIMITS_DEG):
            if not lo <= deg <= hi:
                self.get_logger().error(f'{name} = {deg}° 超出限位 [{lo}, {hi}]，不发送')
                return

        goal = MoveGroup.Goal()
        req = goal.request                       # moveit_msgs/MotionPlanRequest
        req.group_name = 'arm'                   # SRDF 里定义的规划组
        req.num_planning_attempts = 5
        req.allowed_planning_time = 5.0
        req.max_velocity_scaling_factor = velocity_scaling
        req.max_acceleration_scaling_factor = velocity_scaling
        # 起始状态：is_diff=True 表示"用当前实际状态"（来自 /joint_states）
        req.start_state.is_diff = True

        # 目标：每个关节一个 JointConstraint —— 这就是 joint-space 目标
        c = Constraints()
        for name, deg in zip(JOINTS, degrees):
            jc = JointConstraint()
            jc.joint_name = name
            jc.position = math.radians(deg)
            jc.tolerance_above = 0.001
            jc.tolerance_below = 0.001
            jc.weight = 1.0
            c.joint_constraints.append(jc)
        req.goal_constraints.append(c)

        goal.planning_options.plan_only = plan_only
        goal.planning_options.planning_scene_diff.is_diff = True
        goal.planning_options.planning_scene_diff.robot_state.is_diff = True

        self.get_logger().info('等待 move_group ...')
        self.move_client.wait_for_server()
        target = ', '.join(f'{d:.0f}°' for d in degrees)
        self.get_logger().info(f'请求规划到 [{target}]'
                               + ('（只规划）' if plan_only else '（规划 + 执行）'))

        f = self.move_client.send_goal_async(goal)
        rclpy.spin_until_future_complete(self, f)
        handle = f.result()
        if not handle.accepted:
            self.get_logger().error('move_group 拒绝了请求')
            return
        f = handle.get_result_async()
        rclpy.spin_until_future_complete(self, f)
        res = f.result().result

        code = res.error_code.val
        self.get_logger().info(
            f'结果: {ERROR_NAMES.get(code, code)}，规划耗时 {res.planning_time:.3f} s')
        if code == MoveItErrorCodes.SUCCESS:
            self.print_trajectory(res.planned_trajectory.joint_trajectory)

    def print_trajectory(self, traj):
        pts = traj.points
        if not pts:
            return
        total = pts[-1].time_from_start.sec + pts[-1].time_from_start.nanosec * 1e-9
        lines = [f'MoveIt 生成的轨迹：{len(pts)} 个点，总时长 {total:.2f} s',
                 f'  {"t (s)":>6} | {"base":>7} {"shoulder":>8} {"elbow":>7} | 最大关节速度']
        step = max(1, len(pts) // 10)   # 只打印约 10 行
        for i, p in enumerate(pts):
            if i % step and i != len(pts) - 1:
                continue
            t = p.time_from_start.sec + p.time_from_start.nanosec * 1e-9
            q = ' '.join(f'{math.degrees(x):7.1f}°' for x in p.positions)
            v = max(abs(x) for x in p.velocities) if p.velocities else 0.0
            lines.append(f'  {t:6.2f} | {q} | {v:.2f} rad/s')
        self.get_logger().info('\n'.join(lines))

    # ------------------------------------------------------------------
    # 规划场景：障碍物
    # ------------------------------------------------------------------

    def set_obstacle(self, add):
        obj = CollisionObject()
        obj.id = OBSTACLE_ID
        obj.header.frame_id = 'base_link'
        if add:
            # 一个 10 cm 的立方体，放在机械臂左前方 45° 方向、home 姿态下小臂的高度。
            # 从 home 直接转底座到左边 (90°) 时，小臂会扫过这里
            box = SolidPrimitive(type=SolidPrimitive.BOX, dimensions=[0.1, 0.1, 0.1])
            pose = Pose()
            pose.position.x = 0.20
            pose.position.y = 0.20
            pose.position.z = 0.36
            pose.orientation.w = 1.0
            obj.primitives.append(box)
            obj.primitive_poses.append(pose)
            obj.operation = CollisionObject.ADD
        else:
            obj.operation = CollisionObject.REMOVE

        scene = PlanningScene()
        scene.is_diff = True
        scene.world.collision_objects.append(obj)

        self.scene_client.wait_for_service()
        f = self.scene_client.call_async(ApplyPlanningScene.Request(scene=scene))
        rclpy.spin_until_future_complete(self, f)
        ok = f.result().success
        self.get_logger().info(f'{"添加" if add else "删除"}障碍物: {"成功" if ok else "失败"}')


def main():
    parser = argparse.ArgumentParser()
    parser.add_argument('degrees', type=float, nargs='*',
                        help='目标角度（度）：base shoulder elbow')
    parser.add_argument('--plan-only', action='store_true', help='只规划不执行')
    parser.add_argument('--scale', type=float, default=0.5,
                        help='速度/加速度缩放 (0, 1]，默认 0.5')
    parser.add_argument('--add-obstacle', action='store_true')
    parser.add_argument('--clear-obstacle', action='store_true')
    args, ros_args = parser.parse_known_args()
    if args.degrees and len(args.degrees) != 3:
        parser.error('需要 3 个角度：base shoulder elbow')

    rclpy.init(args=ros_args)
    node = JointPlanner()
    try:
        if args.add_obstacle:
            node.set_obstacle(True)
        if args.clear_obstacle:
            node.set_obstacle(False)
        if args.degrees:
            node.plan(args.degrees, args.plan_only, args.scale)
    except KeyboardInterrupt:
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
