include_directories(../include
        ../../common/include)

add_executable(search_tests
        search_tests.c
        nearest_neighbor_test.c)

find_library(CHECK_LIBRARY check)
if (CHECK_LIBRARY)
    target_link_libraries(search_tests ${CHECK_LIBRARY})
endif()

target_link_libraries(search_tests search)