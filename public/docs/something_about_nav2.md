### Something about Nav2 -- 操作指北

1. 安装请看：[Nav2 官网](https://docs.nav2.org/getting_started/index.html)

2. 运行 demo

```bash
ros2 launch nav2_bringup tb3_simulation_launch.py headless:=False
```

> headless 默认值为 true;如果未设置为 false，则不会启动 GZCenvice（3D 视图）。

3. cartographer-ros 功能包用于进行相关操作

```bash
sudo apt install ros-humble-cartographer
sudo apt install ros-humble-cartographer-ros
```

### 参考资料
[Nav 2 Doc](https://docs.nav2.org/getting_started/index.html)

[动手学ROS2](https://fishros.com/d2lros2/#/)