cmake_minimum_required(VERSION 3.16)
project(DataSwap LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(data_swap main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(data_swap PRIVATE Threads::Threads)
