cmake_minimum_required(VERSION 3.16)
project(SelectionSort LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(selection_sort main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(selection_sort PRIVATE Threads::Threads)
