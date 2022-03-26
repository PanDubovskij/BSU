cmake_minimum_required(VERSION 3.21)
project(Vector)

set(CMAKE_CXX_STANDARD 17)

add_library(Vector SHARED vector.cpp vector.h)
target_link_directories(Vector PUBLIC Number)