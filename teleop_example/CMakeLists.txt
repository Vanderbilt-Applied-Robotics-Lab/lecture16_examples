cmake_minimum_required(VERSION 3.8)
project(teleop_example)

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(sensor_msgs REQUIRED)
find_package(sensor_msgs REQUIRED)

## INCLUDE(S)
include_directories(include)

# executables
add_executable(teleop_example src/teleop_example.cpp)

# dependencies
ament_target_dependencies(teleop_example rclcpp sensor_msgs sensor_msgs)

install(TARGETS teleop_example
  DESTINATION lib/${PROJECT_NAME})

ament_package()