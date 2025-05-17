cmake_minimum_required(VERSION 3.31)
project(three_point_password)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_FLAGS_RELEASE "-O2 -DNDEBUG -static -std=c++23")

add_executable(three_point_password main.cpp)