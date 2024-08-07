cmake_minimum_required(VERSION 3.28)
project(Tarea_1_Datos_II)

set(CMAKE_CXX_STANDARD 17)

add_executable(Tarea_1_Datos_II
        generator.cpp
        generator.h
        PagedArray.cpp
        PagedArray.h
        Page.cpp
        Page.h
        sort.cpp)
