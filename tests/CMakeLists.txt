include_directories(
        ${CGGML_SOURCE_DIR}/include
)

add_executable(tests main_test.c
        point_2_test.c
        point_3_test.c
        segment_2_test.c
        sort_test.c
        nearest_neighbor_test.c)

find_library(CHECK_LIBRARY check)
if (CHECK_LIBRARY)
    target_link_libraries(tests ${CHECK_LIBRARY})
endif()

target_link_libraries(tests cggml)
