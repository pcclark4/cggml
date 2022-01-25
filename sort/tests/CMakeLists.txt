include_directories(../include
        ../../common/include)

add_executable(sort_tests
        sort_tests.c
        )

find_library(CHECK_LIBRARY check)
if (CHECK_LIBRARY)
    target_link_libraries(sort_tests ${CHECK_LIBRARY})
endif()

target_link_libraries(sort_tests sort)