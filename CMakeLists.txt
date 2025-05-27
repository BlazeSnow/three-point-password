cmake_minimum_required(VERSION 3.31)
project(three-point-password LANGUAGES CXX VERSION 1.0.3)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(CMAKE_CXX_FLAGS_RELEASE "-O2 -static")

add_executable(three-point-password main.cpp)