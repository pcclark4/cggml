#include "sort.h"
#include "sort_recursive.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define START_BENCH(NAME)                                                      \
    static void NAME(void)                                                     \
    {                                                                          \
        reset_test_arr();                                                      \
        struct timespec startTime = timer_start();

#define END_BENCH(NAME)                                                        \
    struct timespec elapsedTime = timer_stop(&startTime);                      \
    printf("%s: %lds %ld ms\n", #NAME, elapsedTime.tv_sec,                      \
        elapsedTime.tv_nsec / 1000000);                                        \
    }

#define ARR_SIZE 1000000

static unsigned int *baseArr = NULL;
static unsigned int *testArr = NULL;

static struct timespec timer_start(void);
static struct timespec timer_stop(struct timespec *time);

static void reset_test_arr(void)
{
    memcpy(testArr, baseArr, sizeof(int) * ARR_SIZE);
}

START_BENCH(bench_quicksort)
{
    int pivot;
    sort_quick(testArr, ARR_SIZE, &pivot, sizeof(int), &int32_comparator_func);
}
END_BENCH(bench_quicksort)

START_BENCH(bench_heapsort)
{
    sort_heap(testArr, ARR_SIZE, sizeof(int), &int32_comparator_func);
}
END_BENCH(bench_heapsort)

START_BENCH(bench_insertion_sort)
{
    sort_insertion(testArr, ARR_SIZE, sizeof(int), &int32_comparator_func);
}
END_BENCH(bench_insertion_sort)

START_BENCH(bench_radix_sort_bitwise)
    {
        unsigned int *aux = malloc(sizeof(unsigned int) * ARR_SIZE);
        sort_radix_lsd_uint32_bitwise(testArr, aux, ARR_SIZE);
    }
END_BENCH(bench_radix_sort_bitwise)

START_BENCH(bench_radix_sort_bytewise)
{
    unsigned int *aux = malloc(sizeof(unsigned int) * ARR_SIZE);
    sort_radix_lsd_uint32_bytewise(testArr, aux, ARR_SIZE);
}
END_BENCH(bench_radix_sort_bytewise)

int main(void)
{
    baseArr = malloc(sizeof(unsigned int) * ARR_SIZE);
    testArr = malloc(sizeof(unsigned int) * ARR_SIZE);
    int i;
    for (i = 0; i < ARR_SIZE; i++) {
        baseArr[i] = rand() % INT16_T_MAX;
    }

    bench_quicksort();
    bench_heapsort();
//    bench_insertion_sort();
    bench_radix_sort_bitwise();
    bench_radix_sort_bytewise();

    return 0;
}

// http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/
// https://stackoverflow.com/questions/6749621/how-to-create-a-high-resolution-timer-in-linux-to-measure-program-performance
static struct timespec timer_start(void)
{
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &time);
    return time;
}

static struct timespec timer_stop(struct timespec *time)
{
    struct timespec stop;
    clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
    struct timespec temp;
    if ((stop.tv_nsec - time->tv_nsec) < 0) {
        temp.tv_sec = stop.tv_sec - time->tv_sec - 1;
        temp.tv_nsec = 1000000000 + stop.tv_nsec - time->tv_nsec;
    } else {
        temp.tv_sec = stop.tv_sec - time->tv_sec;
        temp.tv_nsec = stop.tv_nsec - time->tv_nsec;
    }
    return temp;
}
