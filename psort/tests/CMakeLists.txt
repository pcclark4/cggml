include_directories(../include
        ../../common/include)

add_executable(psort_tests
        psort_tests.c
        )

find_library(CHECK_LIBRARY check)
if (CHECK_LIBRARY)
    target_link_libraries(psort_tests ${CHECK_LIBRARY})
endif()

target_link_libraries(psort_tests psort)