cmake_minimum_required(VERSION 3.10)

project(my_first_cmake_project)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(my_first_cmake_program main.cpp)
