cmake_minimum_required(VERSION 3.16)
project(ClientQueueAtomic LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(client_queue_atomic main.cpp)

find_package(Threads REQUIRED)
target_link_libraries(client_queue_atomic PRIVATE Threads::Threads)
