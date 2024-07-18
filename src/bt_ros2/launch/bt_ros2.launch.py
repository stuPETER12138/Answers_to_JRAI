from launch import LaunchDescription
from launch_ros.actions import Node, PushRosNamespace
from launch.actions import GroupAction

def generate_launch_description():
    main_server = Node (
        package="bt_ros2",
        executable="sample_server"
    )
    main_client = Node (
        package="bt_ros2",
        executable="sample_client"
    )
    launch_description = LaunchDescription([
        main_server,
        main_client
    ])
    return launch_description

