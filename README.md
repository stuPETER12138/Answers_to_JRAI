# Answers_to_JRAI
![Static Badge](https://img.shields.io/badge/license-MIT-green)
![Static Badge](https://img.shields.io/badge/ros2-Humble-blue)
![Static Badge](https://img.shields.io/badge/CMAKE-3.8-pink)
![Static Badge](https://img.shields.io/badge/python-3.10.12-yellow)

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

题目是啥？ [题目重现](./src/AStar/problem_review.md)

### 第 6 题
安装依赖先

1. 安装 BehaviorTree.CPP

```bash
cd ~
git clone https://github.com/BehaviorTree/BehaviorTree.CPP.git
cd BehaviorTree.CPP
mkdir build/
cd build/
cmake ..
make
sudo make install
```

2. 安装 Groot2

安装链接：[Groot2](https://www.behaviortree.dev/groot/)

（网络原因，作者至今未下载成功，感兴趣的读者请自行尝试

```bash
# 将下载好的文件放在 ～ 的位置
cd ~
# 将文件状态改为可执行
chmod +x Groot2-[your_version]-linux-installer.run
./Groot2-[your_version]-linux-installer.run
```

打开 Groot2：

```bash
cd ~/Groot2/bin
./groot2
```


### 参考资料
[ROS2行为树（C++行为树）BehaviorTree.CPP完全图形化开发，完美支持ROS2话题通信](https://blog.csdn.net/m0_63671696/article/details/131945756)
