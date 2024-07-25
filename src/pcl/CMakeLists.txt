cmake_minimum_required(VERSION 3.8)
project(pcl)

find_package(PCL 1.3 REQUIRED COMPONENTS common io)
include_directories(${PCL_INCLUDE_DIRS})
link_directories(${PCL_LIBRARY_DIRS})
add_definitions(${PCL_DEFINITIONS})

add_executable(pcl_ds pcl_downsampling.cpp)
target_link_libraries(pcl_ds ${PCL_LIBRARIES})
