cmake_minimum_required(VERSION 2.8.3)
project(ros_robotics)
cmake_policy(SET CMP0046 OLD)

find_package(catkin REQUIRED COMPONENTS
  cmake_modules
  interactive_markers
  pluginlib
  roscpp
  std_msgs
  message_generation
)

find_package(OpenCV REQUIRED)

set(CMAKE_CXX_FLAGS "-std=c++0x ${CMAKE_CXX_FLAGS}")

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system)
FIND_LIBRARY(WIRINGPI_LIBRARY wiringPi /opt/wiringPi)


catkin_package(
  CATKIN_DEPENDS message_runtime
)

include_directories(${catkin_INCLUDE_DIRS})


##################################################
## Declare a cpp executable
add_executable(minimal_wiringPi src/minimal_wiringPi.cpp)

## Add cmake target dependencies of the executable/library
## as an example, message headers may need to be generated before nodes
add_dependencies(minimal_wiringPi ros_robotics_generate_messages_cpp wiringPi)

## Specify libraries to link a library or executable target against
target_link_libraries(minimal_wiringPi ${catkin_LIBRARIES} ${OpenCV_LIBS} ${WIRINGPI_LIBRARY})






