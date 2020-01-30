include_directories(
        ../include
        /usr/include
)

add_library(cggml
        ../include/numerical_typedefs.h
        ../include/nearest_neighbor.h
        nearest_neighbor.c
        ../include/point_2.h
        point_2.c
        ../include/point_3.h
        point_3.c
        ../include/nearest_neighbor_point_2.h
        nearest_neighbor_point_2.c
        ../include/nearest_neighbor_point_3.h
        nearest_neighbor_point_3.c
        ../include/sort.h
        sort.c
        ../include/segment_2.h
)

target_link_libraries(cggml m)
