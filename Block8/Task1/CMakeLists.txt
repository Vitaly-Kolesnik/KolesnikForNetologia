cmake_minimum_required(VERSION 3.16)
project(ClientQueue LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(client_queue main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(client_queue PRIVATE Threads::Threads)
