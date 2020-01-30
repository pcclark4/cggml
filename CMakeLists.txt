cmake_minimum_required(VERSION 3.15)
project(cggml C)

set(CMAKE_C_STANDARD 90)
set(CMAKE_C_COMPILER "gcc")
add_compile_options(-std=c90 -pedantic -Wall -Wextra -Wpadded -Wconversion)

add_subdirectory(src)

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME)
    include(CTest)
endif()

if(CMAKE_PROJECT_NAME STREQUAL PROJECT_NAME AND BUILD_TESTING)
    add_subdirectory(tests)
endif()
