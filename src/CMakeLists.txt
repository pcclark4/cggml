include_directories(
        ../include
        /usr/include
)

add_library(cggml
        ../include/numerical_typedefs.h
        nearest_neighbor.c
        ../include/nearest_neighbor.h
        point_2d.c
        ../include/point_2d.h
        point_3d.c
        ../include/point_3d.h
        nearest_neighbor_point_2d.c
        ../include/nearest_neighbor_point_2d.h
        nearest_neighbor_point_3d.c
        ../include/nearest_neighbor_point_3d.h
        ../include/sort.h
        sort.c)

target_link_libraries(cggml m)
