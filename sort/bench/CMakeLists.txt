include_directories(../include ../../common/include)

add_executable(sort_bench sort_bench.c)

target_link_libraries(sort_bench sort)