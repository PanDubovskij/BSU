project(CLionProjects)
cmake_minimum_required(VERSION 3.21)

set(CMAKE_CXX_STANDARD 17)

include_directories(Test)
include_directories(Number)
include_directories(Vector)

add_subdirectory(Test)
add_subdirectory(Number)
add_subdirectory(Vector)

