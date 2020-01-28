#include "main_test.h"
#include "sort.h"
#include <check.h>

static int32_t int32_comparator_func(const void *left, const void *right)
{
    return *(int32_t *) left - *(int32_t *) right;
}

/* Well, I guess I have to do this... */
START_TEST(int32_comparator_test)
{
    int32_t arr[7] = {3, 4, 9, 4, 9, 2, 3};
    ck_assert_int_le(int32_comparator_func(&arr[0], &arr[1]), 0);
    ck_assert_int_gt(int32_comparator_func(&arr[1], &arr[0]), 0);
    ck_assert_int_eq(int32_comparator_func(&arr[0], &arr[6]), 0);
}

START_TEST(sort_insertion_test)
{
    uint32_t i;
    int32_t arr[10] = {5, 3, 8, 10, 6, -1, 2, 4, 7, 9};
    sort_insertion(arr, 10, sizeof(int32_t), &int32_comparator_func);
    for (i = 1; i < 10; i++) {
        ck_assert_int_le(arr[i - 1], arr[i]);
    }
}
END_TEST

START_TEST(sort_selection_test)
{
    uint32_t i;
    int32_t arr[10] = {5, 3, 8, 10, 6, -1, 2, 4, 7, 9};
    sort_selection(arr, 10, sizeof(int32_t), &int32_comparator_func);
    for (i = 1; i < 10; i++) {
        ck_assert_int_le(arr[i - 1], arr[i]);
    }
}

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("sort_test");
    tc_core = tcase_create("default");
    tcase_add_test(tc_core, int32_comparator_test);
    tcase_add_test(tc_core, sort_insertion_test);
    tcase_add_test(tc_core, sort_selection_test);
    suite_add_tcase(s, tc_core);
    return s;
}
