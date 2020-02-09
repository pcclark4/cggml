#include "nearest_neighbor.h"
#include <check.h>
#include <stdlib.h>

float64_t int8_distance_func(const void *va, const void *vb)
{
    const int8_t a = *(const int8_t *) va;
    const int8_t b = *(const int8_t *) vb;
    return abs(b - a);
}

START_TEST(nearest_neighbor_exact_test)
{
    const int8_t neighbors[5] = {1, -2, 54, -53, -8};
    const int8_t query = -3;
    const int8_t *nn = nearest_neighbor_exact(
        &query, neighbors, 5, sizeof(int8_t), int8_distance_func);
    ck_assert_int_eq(-2, *nn);
}
END_TEST

Suite *nearest_neighbor_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("nearest_neighbor_test");
    tc_core = tcase_create("default");
    tcase_add_test(tc_core, nearest_neighbor_exact_test);
    suite_add_tcase(s, tc_core);
    return s;
}
