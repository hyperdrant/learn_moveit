"""
ros2_control 方式启动机械臂

    FollowJointTrajectory action (/arm_controller/follow_joint_trajectory)
                     ↓
    arm_controller (JointTrajectoryController)
                     ↓  command interface: */position
    controller_manager (ros2_control_node)  ← 每 20ms: read → update → write
                     ↓
    RoArmHardware (sim 或 串口)
                     ↑  state interface: */position, */velocity
    joint_state_broadcaster → /joint_states → robot_state_publisher → /tf → RViz

    ros2 launch roarm_control control.launch.py
    ros2 launch roarm_control control.launch.py sim:=false port:=/dev/ttyUSB0

注意：不要和 roarm_driver 同时运行，两者都会发布 /joint_states。
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument, RegisterEventHandler
from launch.conditions import IfCondition
from launch.event_handlers import OnProcessExit
from launch.substitutions import (Command, LaunchConfiguration,
                                  PathJoinSubstitution)
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg = FindPackageShare('roarm_control')
    xacro_path = PathJoinSubstitution([pkg, 'urdf', 'roarm.urdf.xacro'])
    controllers_yaml = PathJoinSubstitution([pkg, 'config', 'controllers.yaml'])
    rviz_path = PathJoinSubstitution(
        [FindPackageShare('my_arm_description'), 'rviz', 'display.rviz'])

    robot_description = {'robot_description': ParameterValue(
        Command(['xacro ', xacro_path,
                 ' sim:=', LaunchConfiguration('sim'),
                 ' port:=', LaunchConfiguration('port')]),
        value_type=str)}

    # controller_manager：加载 URDF 里 <ros2_control> 指定的硬件插件，跑控制循环
    control_node = Node(
        package='controller_manager',
        executable='ros2_control_node',
        parameters=[robot_description, controllers_yaml],
        output='screen',
    )

    # spawner：请求 controller_manager 加载并激活某个 controller
    jsb_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['joint_state_broadcaster', '-c', '/controller_manager'],
    )
    arm_spawner = Node(
        package='controller_manager',
        executable='spawner',
        arguments=['arm_controller', '-c', '/controller_manager'],
    )

    return LaunchDescription([
        DeclareLaunchArgument('sim', default_value='true'),
        DeclareLaunchArgument('port', default_value='/dev/ttyUSB0'),
        DeclareLaunchArgument('rviz', default_value='true'),

        control_node,
        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[robot_description],
        ),
        jsb_spawner,
        # joint_state_broadcaster 激活之后再启动 arm_controller
        RegisterEventHandler(OnProcessExit(
            target_action=jsb_spawner, on_exit=[arm_spawner])),
        Node(
            package='rviz2',
            executable='rviz2',
            arguments=['-d', rviz_path],
            condition=IfCondition(LaunchConfiguration('rviz')),
        ),
    ])
