include_directories(../include)

add_executable(main_test main_test.c
        point_2_test.c
        point_3_test.c
        segment_2_test.c
        sort_test.c
)
target_link_libraries(main_test cggml check pthread)
add_test(NAME main_test COMMAND main_text)