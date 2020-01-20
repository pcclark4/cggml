cmake_minimum_required(VERSION 3.15)
project(cggml C)

set(CMAKE_C_STANDARD 90)

include_directories(
        include
        /usr/include
)

add_executable(cggml
        include/nearest_neighbor_exact.h
        include/point_2d.h
        include/point_3d.h
        src/main.c
        src/nearest_neighbor_exact.c
        src/point_2d.c
        src/point_3d.c include/nearest_neighbor_exact_point_2d.h src/nearest_neighbor_exact_point_2d.c include/nearest_neighbor_exact_point_3d.h src/nearest_neighbor_exact_point_3d.c)

target_link_libraries(cggml m)