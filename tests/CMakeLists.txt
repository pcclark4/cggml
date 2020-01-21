include_directories(../include ../src)

add_executable(point_2d_test point_2d_test.c)
target_link_libraries(point_2d_test m check)

add_executable(point_3d_test point_3d_test.c)
target_link_libraries(point_3d_test m check)

add_test(NAME point_2d_test COMMAND point_2d_test)
add_test(NAME point_3d_test COMMAND point_3d_test)