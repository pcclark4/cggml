include_directories(
        ../include
        /usr/include
)

add_library(cggml
        nearest_neighbor_exact.c
        point_2d.c
        point_3d.c nearest_neighbor_exact_point_2d.c nearest_neighbor_exact_point_3d.c)

target_link_libraries(cggml m)
