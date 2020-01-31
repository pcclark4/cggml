#include "main_test.h"
#include "sort.h"
#include <check.h>

static int32_t int32_comparator_func(const void *left, const void *right)
{
    return *(int32_t *) left - *(int32_t *) right;
}

static void assert_is_sorted(const int32_t *arr, uint32_t arrSize)
{
    uint32_t i;
    for (i = 1; i < arrSize; i++) {
        ck_assert_int_le(arr[i - 1], arr[i]);
    }
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
    int32_t arr[11] = {5, 3, 8, 10, 6, -1, 2, 4, 7, 9, 2};
    sort_insertion(arr, 11, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted(arr, 11);
}
END_TEST

START_TEST(sort_cycle_test)
{
    int32_t arr[11] = {5, 3, 8, 10, 6, -1, 2, 4, 7, 9, 2};
    int32_t tmp;
    sort_cycle(arr, 11, sizeof(int32_t), &int32_comparator_func, &tmp);
    assert_is_sorted(arr, 11);
}
END_TEST

START_TEST(sort_heap_test)
{
    int32_t arr[11] = {5, 3, 8, 10, 6, -1, 2, 4, 7, 9, 2};
    sort_heap(arr, 11, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted(arr, 11);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("sort_test");
    tc_core = tcase_create("default");
    tcase_add_test(tc_core, int32_comparator_test);
    tcase_add_test(tc_core, sort_insertion_test);
    tcase_add_test(tc_core, sort_cycle_test);
    tcase_add_test(tc_core, sort_heap_test);
    suite_add_tcase(s, tc_core);
    return s;
}
