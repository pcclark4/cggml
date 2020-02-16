include_directories(../include ../../common/include)
add_executable(psort_bench psort_bench.c)

target_link_libraries(psort_bench psort)