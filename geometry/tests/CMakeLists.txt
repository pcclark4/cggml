include_directories(../include
        ../../common/include)

add_executable(geometry_tests
        geometry_tests.c
        point_2_test.c
        point_3_test.c
        segment_2_test.c)

find_library(CHECK_LIBRARY check)
if (CHECK_LIBRARY)
    target_link_libraries(geometry_tests ${CHECK_LIBRARY})
endif()

target_link_libraries(geometry_tests geometry)