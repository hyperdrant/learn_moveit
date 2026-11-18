"""
Day 4：用 tf2 验证正运动学（Forward Kinematics）

订阅 /joint_states 拿到关节角，然后：
  1. 用 tf2 查询 base_link → tool0
  2. 自己用公式算末端位置
  3. 打印两者和误差

根据 joint_states 里的关节名自动判断是哪个模型：

two_link_arm（平面二连杆，两个关节都绕 z）：
    x = L1 cos(q1) + L2 cos(q1 + q2)
    y = L1 sin(q1) + L2 sin(q1 + q2)
    z = Z0

three_dof_arm（RoArm-M2：底座绕 z，肩、肘绕 y）：
    先在竖直平面里算水平距离 r 和高度 z，再用底座角 q1 投影到 x, y
    r = l2 sin(q2 + t2) + L3 sin(q2 + q3)
    z = H + l2 cos(q2 + t2) + L3 cos(q2 + q3)
    x = r cos(q1)
    y = r sin(q1)
    其中大臂是 L2A 向上 + L2B 向前的折线，l2 和 t2 是它的等效直线长度和偏角
    （和固件 RoArmM2_computePosbyJointRad 的写法一致）

    ros2 run my_arm_description fk_check
"""
import math
from collections import deque

import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from rclpy.time import Time
from sensor_msgs.msg import JointState
from tf2_ros import Buffer, TransformException, TransformListener

# ---- two_link_arm ----
L1 = 0.2
L2 = 0.2
Z0 = 0.025  # joint1 相对 base_link 的高度

# ---- three_dof_arm（单位 m，来自 RoArm-M2_config.h）----
H = 0.12606    # 底座转轴 → 肩关节的高度 (ARM_L1_LENGTH_MM)
L2A = 0.23682  # 大臂竖直段
L2B = 0.030    # 大臂顶端向前的偏移
L3 = 0.28015   # 小臂
l2 = math.hypot(L2A, L2B)
t2 = math.atan2(L2B, L2A)


def fk_two_link(q):
    q1, q2 = q['joint1'], q['joint2']
    x = L1 * math.cos(q1) + L2 * math.cos(q1 + q2)
    y = L1 * math.sin(q1) + L2 * math.sin(q1 + q2)
    return x, y, Z0


def fk_three_dof(q):
    q1, q2, q3 = q['base_joint'], q['shoulder_joint'], q['elbow_joint']
    r = l2 * math.sin(q2 + t2) + L3 * math.sin(q2 + q3)
    z = H + l2 * math.cos(q2 + t2) + L3 * math.cos(q2 + q3)
    return r * math.cos(q1), r * math.sin(q1), z


class FkCheck(Node):

    def __init__(self):
        super().__init__('fk_check')

        self.declare_parameter('base_frame', 'base_link')
        self.declare_parameter('tip_frame', 'tool0')

        self.tf_buffer = Buffer()
        self.tf_listener = TransformListener(self.tf_buffer, self)

        # 保存最近的 joint_states，按时间戳和 TF 对齐
        self.js_hist = deque(maxlen=100)
        self.create_subscription(JointState, 'joint_states', self.on_js, 10)
        self.create_timer(1.0, self.on_timer)

    def on_js(self, msg):
        self.js_hist.append(msg)

    def on_timer(self):
        if not self.js_hist:
            self.get_logger().info('等待 /joint_states ...')
            return

        # ---- 1. 问 tf2：Time() 表示"buffer 里最新的那一帧" ----
        base = self.get_parameter('base_frame').value
        tip = self.get_parameter('tip_frame').value
        try:
            tf = self.tf_buffer.lookup_transform(base, tip, Time())
        except TransformException as e:
            self.get_logger().warn(f'查询 {base} → {tip} 失败: {e}')
            return

        # robot_state_publisher 发布的 TF 时间戳 = 它所用的 joint_states 的时间戳。
        # 注意 RSP 默认 publish_frequency=20Hz，更快到达的 joint_states 会被丢掉，
        # 所以不能拿"最新的 joint_states"去查 TF，而要用 TF 的时间戳反过来找关节角
        js = next((m for m in reversed(self.js_hist)
                   if m.header.stamp == tf.header.stamp), None)
        if js is None:
            self.get_logger().warn('没找到与 TF 时间戳对应的 joint_states')
            return
        q = dict(zip(js.name, js.position))

        # ---- 2. 自己算 ----
        if 'base_joint' in q:
            x_fk, y_fk, z_fk = fk_three_dof(q)
        else:
            x_fk, y_fk, z_fk = fk_two_link(q)

        t = tf.transform.translation
        err = math.dist((t.x, t.y, t.z), (x_fk, y_fk, z_fk))
        q_str = '   '.join(f'{n} = {math.degrees(v):7.2f}°' for n, v in q.items())
        self.get_logger().info(
            f'\n  {q_str}'
            f'\n  公式: x = {x_fk:+.4f}  y = {y_fk:+.4f}  z = {z_fk:+.4f}'
            f'\n  tf2 : x = {t.x:+.4f}  y = {t.y:+.4f}  z = {t.z:+.4f}'
            f'\n  位置误差 = {err:.2e} m')


def main():
    rclpy.init()
    node = FkCheck()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
