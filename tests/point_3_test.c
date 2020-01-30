#include "main_test.h"
#include "point_3.h"
#include <check.h>

START_TEST(point_3_distance_squared_test)
{
    struct point_3 p1 = {2.0, 3.0, 4.0};
    struct point_3 p2 = {0.0, -25.0, 34.0};
    ck_assert_double_eq(1688.0, point_3_distance_squared(&p1, &p2));
}
END_TEST

START_TEST(point_3_distance_test)
{
    struct point_3 p1 = {2.0, 3.0, 4.0};
    struct point_3 p2 = {0.0, -25.0, 34.0};
    ck_assert_double_eq_tol(41.085277, point_3_distance(&p1, &p2), 0.000001);
}
END_TEST

Suite *point_3_suite()
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("point_3_test");
    tc_core = tcase_create("default");
    tcase_add_test(tc_core, point_3_distance_squared_test);
    tcase_add_test(tc_core, point_3_distance_test);
    suite_add_tcase(s, tc_core);
    return s;
}
