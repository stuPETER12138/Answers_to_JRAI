#!/usr/bin/env python3
import rclpy
from rclpy.node import Node


class RotateWheelNode(Node):
    def __init__(self,name):
        super().__init__(name)
        self.get_logger().info(f"node {name} init..")

def main(args=None):
    """
    ros2运行该节点的入口函数
    1. 导入库文件
    2. 初始化客户端库
    3. 新建节点
    4. spin循环节点
    5. 关闭客户端库
    """
    rclpy.init(args=args) # 初始化rclpy
    node = RotateWheelNode("rotate_sample_bot_wheel")  # 新建一个节点
    rclpy.spin(node) # 保持节点运行，检测是否收到退出指令（Ctrl+C）
    rclpy.shutdown() # 关闭rclpy
