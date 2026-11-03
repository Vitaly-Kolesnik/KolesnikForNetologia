cmake_minimum_required(VERSION 3.16)
project(ParallelForEach LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(parallel_for_each main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(parallel_for_each PRIVATE Threads::Threads)
