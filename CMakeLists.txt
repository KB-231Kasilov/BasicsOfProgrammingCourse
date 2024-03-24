cmake_minimum_required(VERSION 3.26)
project(untitled1 C)

set(CMAKE_C_STANDARD 11)

add_executable(untitled1 main.c
        libs/algorithms/array/array.c
        libs/algorithms/array/array.h
        libs/algorithms/algorithm.h
        libs/algorithms/algorithm.c
)

add_subdirectory(libs)
target_link_libraries(untitled1 data_structures)
target_link_libraries(untitled1 algorithms)