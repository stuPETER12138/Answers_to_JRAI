### 食用方法

1. 安装 [BehaviorTree.CPP]()

```bash
cd ~
git clone https://github.com/BehaviorTree/BehaviorTree.CPP.git
# 装一些依赖
sudo apt-get update
sudo apt-get sqlite3
sudo apt-get install libzmq3-dev libboost-dev
# 需要用到协程
sudo apt-get install libboost-coroutine-dev 
cd BehaviorTree.CPP
mkdir build; cd build
cmake ..
make
sudo make install
```
安装完 BehaviorTree.CPP 后，你应该可以在`/usr/local/include`下找到名为 behaviortree_cpp 的依赖库。

2. 安装 [BehaviorTree.ROS2](https://github.com/BehaviorTree/BehaviorTree.ROS2)

> 建议读者手打命令，复制有风险（可能有错别字

```bash
cd ~
git clone git@github.com:BehaviorTree/BehaviorTree.ROS2.git
cd BehaviorTree.ROS2/
# 首先构建接口相关库
cd cd btcpp_ros2_interfaces/
mkdir build; cd build
cmake ..
make
sudo make install
# 接下来安装 generate_parameter_library 依赖，及其依赖 parameter_traits，及其依赖的依赖：tcb_span, tl_expected, rsl
cd ~
git clone https://github.com/PickNikRobotics/generate_parameter_library.git
git clone https://github.com/PickNikRobotics/RSL.git
git clone https://github.com/PickNikRobotics/cpp_polyfills.git
# 构建 tcb_span, tl_expected
cd tcb_span/
mkdir build; cd build
cmake ..
make
sudo make instal
cd ../../
cd tl_expected/
mkdir build; cd build
cmake ..
make
sudo make instal
# 构建 rsl
cd ~
cd RSL/
mkdir build; cd build
cmake ..
make
sudo make instal
# 构建 parameter_traits
cd ~
cd generate_parameter_library/parameter_traits/
mkdir build; cd build
cmake ..
make
sudo make instal
# 打开另一文件夹，构建 generate_parameter_library
cd ../../
cd generate_parameter_library/
mkdir build; cd build
cmake ..
make
sudo make instal
# 构建 generate_parameter_library_py
# 打开一个能用的 python 环境
# 作者的 ros2 虚拟环境的 python 版本与 hamble 的一致
conda deactivate ros2
python setup.py install
# 最终，回归本心，构建 behaviortree_ros2
# 此时依然在 ros2 环境下
cd ~
cd BehaviorTree.ROS2/
cd behaviortree_ros2/
mkdir build; cd build
cmake ..
make
sudo make instal
# 大功告成！
```

注意：要在`c_cpp_properties.json`中的`"includePath"`下添加`"/usr/local/include/btcpp_ros2_interfaces"`才可以调用 btcpp_ros2_interfaces 相关的头文件。

3. 安装 Groot2

安装链接：[Groot2](https://www.behaviortree.dev/groot/)

网络原因，作者下载得很慢很慢。感兴趣的读者请：尝试

```bash
# 先装一些依赖
sudo apt-get install qtbase5-dev libqt5svg5-dev libzmq3-dev libdw-dev
# 将下载好的文件放在 ～ 的位置
cd ~
# 将文件状态改为可执行
chmod +x Groot2-[your_version]-linux-installer.run
./Groot2-[your_version]-linux-installer.run
```

打开 Groot2：

```bash
cd ~/Groot2/bin/
./groot2
```


### 参考资料
[行为树](https://www.behaviortree.dev/)

[ROS2行为树（C++行为树）BehaviorTree.CPP完全图形化开发，完美支持ROS2话题通信](https://blog.csdn.net/m0_63671696/article/details/131945756)
