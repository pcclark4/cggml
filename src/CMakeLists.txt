include_directories(
        ${CGGML_SOURCE_DIR}/include
)

add_library(cggml
        nearest_neighbor.c
        point_2.c
        point_3.c
        nearest_neighbor_point_2.c
        nearest_neighbor_point_3.c
        sort.c
        segment_2.c)

target_link_libraries(cggml m)
