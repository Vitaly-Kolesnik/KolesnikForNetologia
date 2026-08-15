cmake_minimum_required(VERSION 3.14)
project(ListTest LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(FetchContent)
FetchContent_Declare(
    Catch2
    GIT_REPOSITORY https://github.com/catchorg/Catch2.git
    GIT_TAG        v3.5.0
)
FetchContent_MakeAvailable(Catch2)

add_executable(test_list
    List.cpp
    main.cpp
)

target_include_directories(test_list PRIVATE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(test_list PRIVATE Catch2::Catch2)