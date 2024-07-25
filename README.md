<h1 align="center">Answers to JRAI</h1>

<div align = 'center'>
    <img alt="Static Badge" src="https://img.shields.io/badge/license-MIT-green">
    <img alt="Static Badge" src="https://img.shields.io/badge/Ubuntu-22.04-orange">
    <img alt="Static Badge" src="https://img.shields.io/badge/ROS2-Humble-blue">
</div>

<div align = 'center'>
    <img alt="Static Badge" src="https://img.shields.io/badge/CMAKE-3.8-pink">
    <img alt="Static Badge" src="https://img.shields.io/badge/python-3.10.12-yellow">
</div>

### 千里之行，始于足下

```bash
colcon build
```

### 第 1 - 4 题
- 想看源代码？ [./src/part_one](./src/part_one)

- 记不清题目了？ [题目重现](./src/part_one/problems_review.md)

- 快速查看？

```shell
source install/setup.bash
# 第三题的默认输入为 400，第四题的默认输入为 25
ros2 launch part_one part_one.launch.py
```

### 第 5 题
跑就完了

```bash
cd ./src/AStar/
./Astar
```

- 题目是啥？ [题目重现](./src/AStar/problem_review.md)

### 第 6 题
使用开源行为树框架，设计一个简单的行为树。

安装依赖： [食用方法](./public/docs/How_to_install_something_abiut_BehaviorTree.md)

- 基于 BehaviorTree.CPP 的一个简单的行为树：

```bash
 ./build/bt_cpp/simple_tree
 ```

- 基于 BehaviorTree.ROS2 的动作通信：

```bash
source install/setup.bash
ros2 launch bt_ros2 bt_ros2.launch.py
```

### 第 7 题
要求在 Gazebo 中部署 Navigation 2，实现小车能够导航至任一点击目标点视为完成任务。

<!--感谢`鱼香 ROS`提供 fishbot 机器人模板-->

- [操作指北](./public/docs/something_about_nav2.md)

- [x] 可在Gazebo中显示仿真环境 
- [x] 可在Gazebo中显示机器人模型
- [x] 可在Rviz中显示规划出来的路径
- [x] 机器人可移动至目标点

### 第 8 题
- 步骤一：从我们提供的两个PCD(Point Cloud Data)文件中任选其一，读取pcd文件，对其进行降采样。

- 步骤二：自行选择提取平面的方法（如PCA、RANSAC等）对点云进行处理，获得平面参数并输出。

- 步骤三：将任意一个平面从点云中删除，将处理过后的点云存储为PCD文件。

- [ ] 点云处理可视化
