cmake_minimum_required(VERSION 2.8.3)
project(ros_robotics)


find_package(catkin REQUIRED COMPONENTS
  roscpp
  std_msgs
)

## System dependencies are found with CMake's conventions
find_package(Boost REQUIRED COMPONENTS system)
FIND_LIBRARY(WIRINGPI_LIBRARY wiringPi /opt/wiringPi)


include_directories(${catkin_INCLUDE_DIRS} ${WIRINGPI_LIBRARY})


##################################################
## Declare a cpp executable
add_executable(minimal_wiringPi src/minimal_wiringPi.cpp)
## Specify libraries to link a library or executable target against
target_link_libraries(minimal_wiringPi ${catkin_LIBRARIES} ${WIRINGPI_LIBRARY})






