#include "main_test.h"
#include "sort.h"
#include <check.h>
#include <stdlib.h>

#define ARR_SIZE 500

static int32_t testArr[ARR_SIZE];

/* https://stackoverflow.com/a/1514309 */
static int32_t int32_comparator_func(const void *left, const void *right)
{
    int32_t cmp;
    int32_t a = *(int32_t *) left;
    int32_t b = *(int32_t *) right;
    if ((b < 0) && (a > INT32_T_MAX + b)) {
        cmp = 1;
    } else if ((b > 0) && (a < INT32_T_MIN + b)) {
        cmp = -1;
    } else {
        cmp = a - b;
    }
    return cmp;
}

static void assert_is_sorted(const int32_t *arr, uint32_t arrSize)
{
    uint32_t i;
    for (i = 1; i < arrSize; i++) {
        ck_assert_int_le(arr[i - 1], arr[i]);
    }
}

void setup(void)
{
    /* Fill the array with some random positive and negative numbers. */
    int32_t isNegative;
    int32_t i;
    for (i = 0; i < ARR_SIZE; i++) {
        isNegative = rand() % 2;
        testArr[i] = rand() % INT16_T_MAX;
        if (isNegative) {
            testArr[i] *= -1;
        }
    }
}

void teardown(void)
{}

/* Well, I guess I have to do this... */
START_TEST(int32_comparator_test)
{
    int32_t left = 3;
    int32_t right = 4;
    ck_assert_int_le(int32_comparator_func(&left, &right), 0);
    ck_assert_int_gt(int32_comparator_func(&right, &left), 0);

    right = 3;
    ck_assert_int_eq(int32_comparator_func(&left, &right), 0);

    left = INT32_T_MIN;
    right = INT32_T_MAX;
    ck_assert_int_le(int32_comparator_func(&left, &right), 0);
    ck_assert_int_ge(int32_comparator_func(&right, &left), 0);
    ck_assert_int_eq(int32_comparator_func(&left, &left), 0);
    ck_assert_int_eq(int32_comparator_func(&right, &right), 0);
}

START_TEST(sort_insertion_test)
{
    sort_insertion(testArr, ARR_SIZE, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted(testArr, ARR_SIZE);
}
END_TEST

START_TEST(sort_cycle_test)
{
    int32_t tmp;
    sort_cycle(
        testArr, ARR_SIZE, sizeof(int32_t), &int32_comparator_func, &tmp);
    assert_is_sorted(testArr, ARR_SIZE);
}
END_TEST

START_TEST(sort_heap_test)
{
    sort_heap(testArr, ARR_SIZE, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted(testArr, ARR_SIZE);
}
END_TEST

START_TEST(sort_heap_test_2_elements)
{
    int32_t tinyArr[2] = {0, 1};
    sort_heap(tinyArr, 2, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted(tinyArr, 2);
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_core;
    s = suite_create("sort_test");
    tc_core = tcase_create("default");
    tcase_add_checked_fixture(tc_core, setup, teardown);
    tcase_add_test(tc_core, int32_comparator_test);
    tcase_add_test(tc_core, sort_insertion_test);
    tcase_add_test(tc_core, sort_cycle_test);
    tcase_add_test(tc_core, sort_heap_test);
    tcase_add_test(tc_core, sort_heap_test_2_elements);
    suite_add_tcase(s, tc_core);
    return s;
}
