#ifndef CGGML_MAIN_TEST_H
#define CGGML_MAIN_TEST_H

#include <check.h>

Suite *point_2_suite(void);
Suite *nearest_neighbor_point_2_suite(void);

Suite *point_3_suite(void);
Suite *nearest_neighbor_point_3_suite(void);

Suite *nearest_neighbor_suite(void);

Suite *sort_suite(void);

#endif /* CGGML_MAIN_TEST_H */
