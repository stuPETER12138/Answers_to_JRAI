<div align = 'center'>
    <font size = '60'>Answers to JRAI</font>
</div>

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

安装依赖： [食用方法](./public/docs/How%20to%20install%20something%20abiut%20BehaviorTree.md)

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

### 第 8 题
