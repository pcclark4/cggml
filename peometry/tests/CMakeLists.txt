include_directories(../include
        ../../common/include)

add_executable(peometry_tests
        peometry_tests.c
        point_2_test.c
        point_3_test.c
        segment_2_test.c)

find_library(CHECK_LIBRARY check)
if (CHECK_LIBRARY)
    target_link_libraries(peometry_tests ${CHECK_LIBRARY})
endif()

target_link_libraries(peometry_tests peometry)