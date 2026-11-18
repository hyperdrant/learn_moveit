"""
启动驱动 + robot_state_publisher + RViz

    /joint_states (driver)  →  robot_state_publisher  →  /tf  →  RViz

    ros2 launch roarm_driver driver.launch.py                          # 模拟模式
    ros2 launch roarm_driver driver.launch.py sim:=false port:=/dev/ttyUSB0
    ros2 launch roarm_driver driver.launch.py rviz:=false              # 不开 RViz
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
    # URDF 和 RViz 配置复用 my_arm_description 里的
    desc_share = FindPackageShare('my_arm_description')
    urdf_path = PathJoinSubstitution([desc_share, 'urdf', 'three_dof_arm.urdf'])
    rviz_path = PathJoinSubstitution([desc_share, 'rviz', 'display.rviz'])
    robot_description = ParameterValue(
        Command(['xacro ', urdf_path]), value_type=str)

    return LaunchDescription([
        DeclareLaunchArgument('sim', default_value='true',
                              description='true=模拟, false=连接真机'),
        DeclareLaunchArgument('port', default_value='/dev/ttyUSB0',
                              description='真机串口'),
        DeclareLaunchArgument('rviz', default_value='true'),

        Node(
            package='roarm_driver',
            executable='driver',
            parameters=[{
                'sim': ParameterValue(LaunchConfiguration('sim'), value_type=bool),
                'port': LaunchConfiguration('port'),
            }],
            output='screen',
        ),

        Node(
            package='robot_state_publisher',
            executable='robot_state_publisher',
            parameters=[{'robot_description': robot_description}],
        ),

        Node(
            package='rviz2',
            executable='rviz2',
            arguments=['-d', rviz_path],
            condition=IfCondition(LaunchConfiguration('rviz')),
        ),
    ])
