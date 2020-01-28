#include "main_test.h"
#include "point_2d.h"
#include <check.h>
#include <stdio.h>

START_TEST(point_2d_distance_squared_test)
{
    struct point_2d p1 = {-5.0, 0.0};
    struct point_2d p2 = {5.0, 0.0};
    ck_assert_double_eq(100.0, point_2d_distance_squared(&p1, &p2));
}
END_TEST

START_TEST(point_2d_distance_test)
{
    struct point_2d p1 = {0.0, 10.0};
    struct point_2d p2 = {0.0, -2.5};
    ck_assert_double_eq(12.5, point_2d_distance(&p1, &p2));
}
END_TEST

Suite *point_2d_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("point_2d_test");
    tc_core = tcase_create("default");
    tcase_add_test(tc_core, point_2d_distance_squared_test);
    tcase_add_test(tc_core, point_2d_distance_test);
    suite_add_tcase(s, tc_core);
    return s;
}
