cmake_minimum_required(VERSION 3.10)

# Название проекта
project(my_first_cmake_project)

# Настройка стандарта C++
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Создание исполняемого файла
add_executable(my_first_cmake_program main.cpp)