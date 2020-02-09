#include "peometry_tests.h"
#include "segment_2.h"
#include <check.h>

START_TEST(segment_2_length_test)
{
    const struct segment_2 seg = {{5.0, 0.0}, {-5.0, 0.0}};
    ck_assert_double_eq(10.0, segment_2_length(&seg));
}
END_TEST

Suite *segment_2_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("segment_2_test");
    tc_core = tcase_create("default");
    tcase_add_test(tc_core, segment_2_length_test);
    suite_add_tcase(s, tc_core);
    return s;
}
