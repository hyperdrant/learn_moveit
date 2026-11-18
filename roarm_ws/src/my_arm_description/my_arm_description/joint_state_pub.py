"""
Day 3：自己发布 /joint_states

参数 model 要和 launch 里加载的 URDF 对应：
  - two_link_arm ：joint1, joint2           （用 q1_deg, q2_deg）
  - three_dof_arm：base_joint, shoulder_joint, elbow_joint
                                            （用 q1_deg, q2_deg, q3_deg）

两种模式（参数 mode）：
  - fixed：发布固定角度，可以运行时修改：
        ros2 param set /joint_state_pub q1_deg 30.0
  - sine ：各关节做正弦摆动，看 RViz 里机械臂动起来

    ros2 run my_arm_description joint_state_pub
    ros2 run my_arm_description joint_state_pub --ros-args -p mode:=sine
    ros2 run my_arm_description joint_state_pub --ros-args -p model:=three_dof_arm
"""
import math

import rclpy
from rclpy.executors import ExternalShutdownException
from rclpy.node import Node
from sensor_msgs.msg import JointState

# name 必须和 URDF 里 <joint name="..."> 完全一致
JOINT_NAMES = {
    'two_link_arm': ['joint1', 'joint2'],
    'three_dof_arm': ['base_joint', 'shoulder_joint', 'elbow_joint'],
}


class JointStatePub(Node):

    def __init__(self):
        super().__init__('joint_state_pub')

        self.declare_parameter('model', 'two_link_arm')
        self.declare_parameter('mode', 'fixed')
        self.declare_parameter('q1_deg', 30.0)
        self.declare_parameter('q2_deg', 45.0)
        # three_dof_arm 的肘关节：90° 时小臂垂直于大臂
        self.declare_parameter('q3_deg', 60.0)
        self.declare_parameter('rate', 30.0)

        model = self.get_parameter('model').value
        if model not in JOINT_NAMES:
            raise ValueError(f'未知 model: {model}，可选 {list(JOINT_NAMES)}')
        self.names = JOINT_NAMES[model]

        self.pub = self.create_publisher(JointState, 'joint_states', 10)

        rate = self.get_parameter('rate').value
        self.t0 = self.get_clock().now()
        self.timer = self.create_timer(1.0 / rate, self.on_timer)

    def on_timer(self):
        mode = self.get_parameter('mode').value

        if mode == 'sine':
            t = (self.get_clock().now() - self.t0).nanoseconds * 1e-9
            if len(self.names) == 2:
                q = [1.0 * math.sin(0.5 * t),
                     1.5 * math.sin(0.8 * t)]
            else:
                # 范围留在固件限位内：肩 ±90°，肘 -45°~180°
                q = [1.0 * math.sin(0.5 * t),
                     0.6 * math.sin(0.7 * t),
                     1.2 + 0.6 * math.sin(0.9 * t)]
        else:
            q = [math.radians(self.get_parameter(f'q{i + 1}_deg').value)
                 for i in range(len(self.names))]

        msg = JointState()
        msg.header.stamp = self.get_clock().now().to_msg()
        msg.name = self.names
        # 单位是弧度
        msg.position = q
        self.pub.publish(msg)


def main():
    rclpy.init()
    node = JointStatePub()
    try:
        rclpy.spin(node)
    except (KeyboardInterrupt, ExternalShutdownException):
        pass
    finally:
        node.destroy_node()
        rclpy.try_shutdown()


if __name__ == '__main__':
    main()
