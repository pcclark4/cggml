include_directories(../include
        ../../common/include)

add_executable(psearch_tests
        psearch_tests.c
        nearest_neighbor_test.c)

find_library(CHECK_LIBRARY check)
if (CHECK_LIBRARY)
    target_link_libraries(psearch_tests ${CHECK_LIBRARY})
endif()

target_link_libraries(psearch_tests psearch)