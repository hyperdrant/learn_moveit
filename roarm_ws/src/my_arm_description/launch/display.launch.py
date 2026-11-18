"""
显示机械臂：robot_state_publisher + RViz

数据流：
    /joint_states  →  robot_state_publisher (读 URDF)  →  /tf, /tf_static

用法：
    # Day 2：用滑块 GUI 发布 /joint_states
    ros2 launch my_arm_description display.launch.py
    ros2 launch my_arm_description display.launch.py model:=three_dof_arm

    # Day 3：不启动 GUI，改用自己写的节点发布 /joint_states
    ros2 launch my_arm_description display.launch.py gui:=false
    ros2 run my_arm_description joint_state_pub
"""
from launch import LaunchDescription
from launch.actions import DeclareLaunchArgument
from launch.conditions import IfCondition
from launch.substitutions import (Command, LaunchConfiguration,
                                  PathJoinSubstitution)
from launch_ros.actions import Node
from launch_ros.parameter_descriptions import ParameterValue
from launch_ros.substitutions import FindPackageShare


def generate_launch_description():
    pkg_share = FindPackageShare('my_arm_description')
    urdf_path = PathJoinSubstitution(
        [pkg_share, 'urdf', [LaunchConfiguration('model'), '.urdf']])
    rviz_path = PathJoinSubstitution([pkg_share, 'rviz', 'display.rviz'])

    # 用 xacro 读文件：纯 URDF 也能直接处理，以后换成 .xacro 也不用改这里
    robot_description = ParameterValue(
        Command(['xacro ', urdf_path]), value_type=str)

    gui = LaunchConfiguration('gui')

    return LaunchDescription([
        DeclareLaunchArgument(
            'model', default_value='two_link_arm',
            description='urdf/ 下的模型文件名：two_link_arm 或 three_dof_arm'),
        DeclareLaunchArgument(
            'gui', default_value='true',
            description='是否启动 joint_state_publisher_gui 滑块'),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': robot_description}],
        ),

        Node(
            package='joint_state_publisher_gui',
            executable='joint_state_publisher_gui',
            condition=IfCondition(gui),
        ),

        Node(
            package='rviz2',
            executable='rviz2',
            arguments=['-d', rviz_path],
        ),
    ])
