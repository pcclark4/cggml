#include "sort.h"
#include "sort_recursive.h"
#include <check.h>
#include <stdlib.h>

#define ARR_SIZE 200

static int32_t testArr[ARR_SIZE];

struct keyed_item
{
    uint32_t key;
    const char *name;
    uint8_t age;
};

static uint32_t keyed_item_keygen_func(const void *in)
{
    return ((const struct keyed_item *) in)->key;
}

static void assert_is_sorted_int32(const int32_t *arr, uint32_t arrSize)
{
    if (arrSize > 1) {
        uint32_t i;
        for (i = 1; i < arrSize; i++) {
            ck_assert_int_le(arr[i - 1], arr[i]);
        }
    }
}

static void assert_is_sorted_uint32(const uint32_t *arr, uint32_t arrSize)
{
    if (arrSize > 1) {
        uint32_t i;
        for (i = 1; i < arrSize; i++) {
            ck_assert_int_le(arr[i - 1], arr[i]);
        }
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
END_TEST

START_TEST(sort_insertion_test)
{
    sort_insertion(testArr, ARR_SIZE, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted_int32(testArr, ARR_SIZE);
}
END_TEST

START_TEST(sort_insertion_test_1_element)
{
    int32_t tinyArr[1] = {1};
    sort_insertion(tinyArr, 1, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted_int32(tinyArr, 1);
}
END_TEST

START_TEST(sort_insertion_test_2_elements)
{
    int32_t tinyArr[2] = {0, 1};
    sort_insertion(tinyArr, 2, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted_int32(tinyArr, 2);
}
END_TEST

START_TEST(sort_cycle_test)
{
    int32_t tmp;
    sort_cycle(
        testArr, ARR_SIZE, sizeof(int32_t), &int32_comparator_func, &tmp);
    assert_is_sorted_int32(testArr, ARR_SIZE);
}
END_TEST

START_TEST(sort_cycle_test_1_element)
{
    int32_t tmp;
    int32_t tinyArr[1] = {1};
    sort_cycle(tinyArr, 1, sizeof(int32_t), &int32_comparator_func, &tmp);
    assert_is_sorted_int32(tinyArr, 1);
}
END_TEST

START_TEST(sort_cycle_test_2_elements)
{
    int32_t tmp;
    int32_t tinyArr[2] = {0, 1};
    sort_cycle(tinyArr, 2, sizeof(int32_t), &int32_comparator_func, &tmp);
    assert_is_sorted_int32(tinyArr, 2);
}
END_TEST

START_TEST(sort_heap_test)
{
    sort_heap(testArr, ARR_SIZE, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted_int32(testArr, ARR_SIZE);
}
END_TEST

START_TEST(sort_heap_test_1_element)
{
    int32_t tinyArr[1] = {1};
    sort_heap(tinyArr, 1, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted_int32(tinyArr, 1);
}
END_TEST

START_TEST(sort_heap_test_2_elements)
{
    int32_t tinyArr[2] = {0, 1};
    sort_heap(tinyArr, 2, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted_int32(tinyArr, 2);
}
END_TEST

START_TEST(sort_counting_generic_test)
{
    enum
    {
        arrSize = 6,
        kSize = 32
    };
    struct keyed_item inputArr[arrSize] = {{15, "Cory", 22}, {3, "Phil", 29},
        {2, "Jim", 67}, {24, "Matt", 35}, {32, "Pam", 19}, {15, "Brad", 45}};
    struct keyed_item outputArr[arrSize] = {0};
    uint32_t countArr[kSize + 1] = {0};
    uint32_t i;

    sort_counting_generic(inputArr, outputArr, arrSize,
        sizeof(struct keyed_item), &keyed_item_keygen_func, countArr, 2, kSize);

    /* Assert that they are in key order */
    for (i = 1; i < arrSize; i++) {
        ck_assert_int_le(outputArr[i - 1].key, outputArr[i].key);
    }

    /* Assert that the sort was stable */
    ck_assert_pstr_eq(outputArr[2].name, "Cory");
}
END_TEST

START_TEST(sort_counting_uint32_test)
{
    enum
    {
        minKey = 0,
        maxKey = 50000
    };
    uint32_t inputArr[ARR_SIZE] = {0};
    uint32_t countingArr[(maxKey - minKey) + 1] = {0};
    uint32_t i;

    for (i = 0; i < ARR_SIZE; i++) {
        inputArr[i] = rand() % ((maxKey - minKey) + 1) + minKey;
    }

    sort_counting_uint32(inputArr, ARR_SIZE, countingArr, minKey, maxKey);
    assert_is_sorted_uint32(inputArr, ARR_SIZE);
}
END_TEST

START_TEST(sort_radix_lsd_uint32_test)
{
    uint32_t arr[ARR_SIZE] = {0};
    uint32_t auxArr[ARR_SIZE] = {0};
    uint32_t i;
    for (i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand();
    }
    sort_radix_lsd_uint32_bitwise(arr, auxArr, ARR_SIZE);
    assert_is_sorted_uint32(arr, ARR_SIZE);
}
END_TEST

START_TEST(sort_radix_lsd_uint32_bytewise_test)
{
    uint32_t arr[ARR_SIZE] = {0};
    uint32_t auxArr[ARR_SIZE] = {0};
    uint32_t i;
    for (i = 0; i < ARR_SIZE; i++) {
        arr[i] = rand();
    }
    sort_radix_lsd_uint32_bytewise(arr, auxArr, ARR_SIZE);
    assert_is_sorted_uint32(arr, ARR_SIZE);
}
END_TEST

START_TEST(sort_quick_test)
{
    int32_t pivot = 0;
    sort_quick(
        testArr, ARR_SIZE, &pivot, sizeof(int32_t), &int32_comparator_func);
    assert_is_sorted_int32(testArr, ARR_SIZE);
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
    tcase_add_test(tc_core, sort_insertion_test_1_element);
    tcase_add_test(tc_core, sort_insertion_test_2_elements);
    tcase_add_test(tc_core, sort_cycle_test);
    tcase_add_test(tc_core, sort_cycle_test_1_element);
    tcase_add_test(tc_core, sort_cycle_test_2_elements);
    tcase_add_test(tc_core, sort_heap_test);
    tcase_add_test(tc_core, sort_heap_test_1_element);
    tcase_add_test(tc_core, sort_heap_test_2_elements);
    tcase_add_test(tc_core, sort_counting_generic_test);
    tcase_add_test(tc_core, sort_counting_uint32_test);
    tcase_add_test(tc_core, sort_radix_lsd_uint32_test);
    tcase_add_test(tc_core, sort_radix_lsd_uint32_bytewise_test);
    tcase_add_test(tc_core, sort_quick_test);
    suite_add_tcase(s, tc_core);
    return s;
}

int main(void)
{
    int32_t numFailed;
    SRunner *sr = srunner_create(sort_suite());
    /* CK_NOFORK allows us to attach debugger while running tests
     * https://github.com/vndmtrx/check-cmake-example */
    srunner_set_fork_status(sr, CK_NOFORK);

    srunner_run_all(sr, CK_NORMAL);
    numFailed = srunner_ntests_failed(sr);
    srunner_free(sr);

    return (numFailed == 0) ? EXIT_SUCCESS : EXIT_FAILURE;
}
