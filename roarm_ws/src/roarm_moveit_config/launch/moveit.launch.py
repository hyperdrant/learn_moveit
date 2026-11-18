"""
Week 4：MoveIt 2 + ros2_control

    RViz MotionPlanning 面板 / plan_joints.py
                 │  MoveGroup action (/move_action)
                 ▼
            move_group            ← 读 URDF + SRDF + joint_limits + OMPL + 控制器配置
                 │  ① OMPL 规划路径（检查限位、碰撞）
                 │  ② 时间参数化（加上速度/加速度 → 轨迹）
                 │  ③ FollowJointTrajectory action
                 ▼
     /arm_controller/follow_joint_trajectory      ← Week 3 的 JTC
                 ▼
          ros2_control → RoArmHardware (sim / 串口)

    ros2 launch roarm_moveit_config moveit.launch.py
    ros2 launch roarm_moveit_config moveit.launch.py sim:=false port:=/dev/ttyUSB0
"""
from launch import LaunchDescription
from launch.actions import (DeclareLaunchArgument, GroupAction,
                            IncludeLaunchDescription)
from launch.conditions import IfCondition
from launch.launch_description_sources import PythonLaunchDescriptionSource
from launch.substitutions import LaunchConfiguration, PathJoinSubstitution
from launch_ros.actions import Node
from launch_ros.substitutions import FindPackageShare
from moveit_configs_utils import MoveItConfigsBuilder

from ament_index_python.packages import get_package_share_directory


def generate_launch_description():
    sim = LaunchConfiguration('sim')
    port = LaunchConfiguration('port')

    # MoveItConfigsBuilder 把 MoveIt 需要的所有配置汇总成一个参数字典
    # 相对路径都是相对于 roarm_moveit_config 包
    moveit_config = (
        MoveItConfigsBuilder('roarm', package_name='roarm_moveit_config')
        # URDF：直接用 Week 3 的 xacro（几何 + <ros2_control>），保证和控制层一致
        .robot_description(
            file_path=get_package_share_directory('roarm_control') + '/urdf/roarm.urdf.xacro',
            mappings={'sim': sim, 'port': port})
        .robot_description_semantic(file_path='config/roarm.srdf')
        .robot_description_kinematics(file_path='config/kinematics.yaml')
        .joint_limits(file_path='config/joint_limits.yaml')
        .planning_pipelines(pipelines=['ompl'])          # 读 config/ompl_planning.yaml
        .trajectory_execution(file_path='config/moveit_controllers.yaml')
        .planning_scene_monitor(
            publish_robot_description=True,
            publish_robot_description_semantic=True)
        .to_moveit_configs()
    )

    # ① 控制层：Week 3 的 ros2_control + JTC + RSP（不在这里开 RViz）
    #
    # 注意 GroupAction：launch 参数默认是全局共享的，include 时传的 rviz:=false
    # 会把本文件的 rviz 参数也改成 false，导致下面 MoveIt 的 RViz 也不启动。
    # GroupAction(scoped=True) 让这些参数只在组内生效
    control = GroupAction(scoped=True, actions=[IncludeLaunchDescription(
        PythonLaunchDescriptionSource(PathJoinSubstitution(
            [FindPackageShare('roarm_control'), 'launch', 'control.launch.py'])),
        launch_arguments={'sim': sim, 'port': port, 'rviz': 'false'}.items(),
    )])

    # ② 规划层：move_group 是 MoveIt 的核心节点
    move_group = Node(
        package='moveit_ros_move_group',
        executable='move_group',
        parameters=[moveit_config.to_dict()],
        output='screen',
    )

    # ③ RViz + MotionPlanning 插件
    #   插件需要 URDF / SRDF 来显示机器人，需要 IK 配置来拖动末端标记；
    #   规划本身由 move_group 完成，所以不用传 OMPL 和 joint_limits
    rviz = Node(
        package='rviz2',
        executable='rviz2',
        arguments=['-d', PathJoinSubstitution(
            [FindPackageShare('roarm_moveit_config'), 'config', 'moveit.rviz'])],
        parameters=[
            moveit_config.robot_description,
            moveit_config.robot_description_semantic,
        ],
        condition=IfCondition(LaunchConfiguration('rviz')),
    )

    return LaunchDescription([
        DeclareLaunchArgument('sim', default_value='true'),
        DeclareLaunchArgument('port', default_value='/dev/ttyUSB0'),
        DeclareLaunchArgument('rviz', default_value='true'),
        control,
        move_group,
        rviz,
    ])
