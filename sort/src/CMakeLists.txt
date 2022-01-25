include_directories(../include
        ../../common/include)

add_library(sort
        sort.c
        sort_recursive.c sort_common.c)
