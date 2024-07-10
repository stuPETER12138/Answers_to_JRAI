cmake_minimum_required(VERSION 3.8)
project(part_one)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(rclcpp_action REQUIRED)
find_package(std_msgs REQUIRED)
find_package(interfaces REQUIRED)

add_executable(node_1_publisher src/node_1_publisher.cpp)
ament_target_dependencies(node_1_publisher rclcpp interfaces)
add_executable(node_1_subscriber src/node_1_subscriber.cpp)
ament_target_dependencies(node_1_subscriber rclcpp interfaces)
add_executable(node_2_01 src/node_2_01.cpp)
ament_target_dependencies(node_2_01 rclcpp std_msgs)
add_executable(node_2_02 src/node_2_02.cpp)
ament_target_dependencies(node_2_02 rclcpp std_msgs)
add_executable(node_2_03 src/node_2_03.cpp)
ament_target_dependencies(node_2_03 rclcpp std_msgs)
add_executable(node_3_server src/node_3_server.cpp)
ament_target_dependencies(node_3_server rclcpp interfaces)
add_executable(node_3_client src/node_3_client.cpp)
ament_target_dependencies(node_3_client rclcpp interfaces)
add_executable(node_4_server src/node_4_server.cpp)
ament_target_dependencies(node_4_server rclcpp rclcpp_action interfaces)
add_executable(node_4_client src/node_4_client.cpp)
ament_target_dependencies(node_4_client rclcpp rclcpp_action interfaces)

install(TARGETS
node_1_publisher
node_1_subscriber
node_2_01
node_2_02
node_2_03
node_3_server
node_3_client
node_4_server
node_4_client
DESTINATION lib/${PROJECT_NAME})

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # comment the line when a copyright and license is added to all source files
  set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # comment the line when this package is in a git repo and when
  # a copyright and license is added to all source files
  set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

ament_package()
