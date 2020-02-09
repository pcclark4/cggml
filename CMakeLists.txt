cmake_minimum_required(VERSION 3.15)
project(CGGML
        DESCRIPTION "A geometry-ish library"
        VERSION 0.0.0.1
        LANGUAGES C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_COMPILER "gcc")
add_compile_options(-std=c90 -pedantic -Wall -Wextra -Wpadded -Wconversion)

add_subdirectory(peometry)
add_subdirectory(psort)
add_subdirectory(psearch)
