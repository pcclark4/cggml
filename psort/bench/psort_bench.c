#include "sort.h"
#include "sort_recursive.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define NANOS_PER_MILLI 1000000L

#define START_BENCH(NAME)                                                      \
    static void NAME(void)                                                     \
    {                                                                          \
        struct timespec startTime;                                             \
        struct timespec elapsedTime;                                           \
        reset_test_arr();                                                      \
        startTime = timer_start();

#define END_BENCH(NAME)                                                        \
    elapsedTime = timer_stop(&startTime);                                      \
    printf("%s: %lds %ld ms\n", #NAME, elapsedTime.tv_sec,                     \
        elapsedTime.tv_nsec / NANOS_PER_MILLI);                                \
    }

#define ARR_SIZE 1000000L
#define MAX_NUM 1000L

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

START_BENCH(bench_counting_sort)
{
    uint32_t *countArr = malloc(sizeof(uint32_t) * (MAX_NUM + 1L));
    sort_counting_uint32(testArr, ARR_SIZE, countArr, 0L, MAX_NUM);
    free(countArr);
}
END_BENCH(bench_counting_sort)

static uint32_t uint32_keygen(const void *obj)
{
    return *(uint32_t *) obj;
}

START_BENCH(bench_counting_sort_generic)
{
    uint32_t *countArr = malloc(sizeof(uint32_t) * (MAX_NUM + 1L));
    uint32_t *outArr = malloc(sizeof(uint32_t) * ARR_SIZE);
    sort_counting_generic(testArr, outArr, ARR_SIZE, sizeof(uint32_t),
        &uint32_keygen, countArr, 0L, MAX_NUM);
    free(outArr);
    free(countArr);
}
END_BENCH(bench_counting_sort_generic)

START_BENCH(bench_radix_sort_bitwise)
{
    unsigned int *aux = malloc(sizeof(int) * ARR_SIZE);
    sort_radix_lsd_uint32_bitwise(testArr, aux, ARR_SIZE);
    free(aux);
}
END_BENCH(bench_radix_sort_bitwise)

START_BENCH(bench_radix_sort_bytewise)
{
    unsigned int *aux = malloc(sizeof(int) * ARR_SIZE);
    sort_radix_lsd_uint32_bytewise(testArr, aux, ARR_SIZE);
    free(aux);
}
END_BENCH(bench_radix_sort_bytewise)

int main(void)
{
    int i;
    baseArr = malloc(sizeof(int) * ARR_SIZE);
    testArr = malloc(sizeof(int) * ARR_SIZE);
    for (i = 0; i < ARR_SIZE; i++) {
        baseArr[i] = rand() % (MAX_NUM + 1L);
    }

    bench_quicksort();
    bench_heapsort();
    bench_counting_sort();
    bench_counting_sort_generic();
    bench_radix_sort_bitwise();
    bench_radix_sort_bytewise();

    free(testArr);
    free(baseArr);
    return 0;
}

/* http://www.guyrutenberg.com/2007/09/22/profiling-code-using-clock_gettime/
 * https://stackoverflow.com/questions/6749621/how-to-create-a-high-resolution-timer-in-linux-to-measure-program-performance
 */
static struct timespec timer_start(void)
{
    struct timespec time;
    clock_gettime(CLOCK_MONOTONIC_RAW, &time);
    return time;
}

static struct timespec timer_stop(struct timespec *time)
{
    struct timespec stop;
    struct timespec temp;

    clock_gettime(CLOCK_MONOTONIC_RAW, &stop);
    if ((stop.tv_nsec - time->tv_nsec) < 0) {
        temp.tv_sec = stop.tv_sec - time->tv_sec - 1;
        temp.tv_nsec = 1000000000 + stop.tv_nsec - time->tv_nsec;
    } else {
        temp.tv_sec = stop.tv_sec - time->tv_sec;
        temp.tv_nsec = stop.tv_nsec - time->tv_nsec;
    }
    return temp;
}
