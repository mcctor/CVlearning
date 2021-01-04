cmake_minimum_required(VERSION 3.2)
project(CVlearning)

find_package(OpenCV REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

add_executable(peep peep.cpp)

target_link_libraries(peep ${OpenCV_LIBS})
