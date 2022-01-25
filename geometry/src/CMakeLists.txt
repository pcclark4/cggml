include_directories(../include
        ../../common/include)

add_library(geometry
        point_2.c
        point_3.c
        segment_2.c)

target_link_libraries(geometry m)