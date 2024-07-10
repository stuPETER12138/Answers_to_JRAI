from launch import LaunchDescription
from launch_ros.actions import Node, PushRosNamespace
from launch.actions import GroupAction

def generate_launch_description():
    node_1_publisher = Node(
        package="part_one",
        executable="node_1_publisher"
    )
    node_1_subscriber = Node(
        package="part_one",
        executable="node_1_subscriber"
    )
    node_2_01 = Node(
        package="part_one",
        executable="node_2_01"
    )
    node_2_02 = Node(
        package="part_one",
        executable="node_2_02"
    )
    node_2_03 = Node(
        package="part_one",
        executable="node_2_03"
    )
    node_3_server = Node(
        package="part_one",
        executable="node_3_server"
    )
    node_3_client = Node(
        package="part_one",
        executable="node_3_client",
        parameters=[{'num': 400}]
    )
    node_4_server = Node(
        package="part_one",
        executable="node_4_server"
    )
    node_4_client = Node(
        package="part_one",
        executable="node_4_client"
    )
    group01 = GroupAction(actions=[
        PushRosNamespace(namespace="group01"),
        node_1_publisher,
        node_1_subscriber
    ])
    group02 = GroupAction(actions=[
        PushRosNamespace(namespace="group02"),
        node_2_01,
        node_2_02,
        node_2_03
    ])
    group03 = GroupAction(actions=[
        PushRosNamespace(namespace="group03"),
        node_3_server,
        node_3_client
    ])
    group04 = GroupAction(actions=[
        PushRosNamespace(namespace="group04"),
        node_4_server,
        node_4_client
    ])
    launch_description = LaunchDescription([
        group01,
        group02,
        group03,
        group04
    ])
    return launch_description
