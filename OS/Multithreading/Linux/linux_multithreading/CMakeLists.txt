cmake_minimum_required(VERSION 3.21)
project(linux_multithreading)

set(CMAKE_CXX_STANDARD 17)

add_executable(linux_multithreading main.cpp Matrix.cpp Matrix.h)
