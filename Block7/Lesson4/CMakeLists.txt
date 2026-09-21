cmake_minimum_required(VERSION 3.15)
project(PostgresClientManager CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Находим пакет libpqxx
find_package(pqxx CONFIG REQUIRED)

add_executable(PostgresClientManager main.cpp)

# Подключаем libpqxx к исполняемому файлу
target_link_libraries(PostgresClientManager PRIVATE pqxx::pqxx)
