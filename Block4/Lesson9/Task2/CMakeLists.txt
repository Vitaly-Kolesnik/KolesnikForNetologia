cmake_minimum_required(VERSION 3.10)
project(GeometryFigures)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(include)

add_executable(geometry_figures
    src/main.cpp
    src/Triangle.cpp
    src/RightTriangle.cpp
    src/IsoscelesTriangle.cpp
    src/EquilateralTriangle.cpp
    src/Quadrilateral.cpp
    src/Parallelogram.cpp
    src/Rectangle.cpp
    src/Square.cpp
    src/Rhombus.cpp
)