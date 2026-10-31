cmake_minimum_required(VERSION 3.16)
project(VectorSum LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(vector_sum main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(vector_sum PRIVATE Threads::Threads)
