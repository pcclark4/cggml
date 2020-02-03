#ifndef CGGML_SORT_H
#define CGGML_SORT_H

#include "numerical_typedefs.h"
#include "stddef.h"

typedef int32_t (*comparator_func)(const void *, const void *);
typedef uint32_t (*keygen_func)(const void *);

/* Extremely fast for small array sizes
 * https://en.wikipedia.org/wiki/Insertion_sort */
void sort_insertion(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp);

/* Efficient in environments where writes are extremely expensive (flash mem)
 * https://en.wikipedia.org/wiki/Cycle_sort
 * Caller must pass an extra elementSize-bytes to hold temporary value
 * necessary for the algorithm */
void sort_cycle(void *arr, uint32_t arrSize, size_t elementSize,
    comparator_func cmp, void *tmp);

/* Fastest for larger data sets
 * https://en.wikipedia.org/wiki/Heapsort
 * https://rosettacode.org/wiki/Sorting_algorithms/Heapsort#C */
void sort_heap(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp);

void sort_counting(const void *inputArr, void *outputArr,
    uint32_t arrSize, size_t eleSize, keygen_func key, uint32_t *countArr,
    uint32_t kSize);

void sort_counting_uint32(
    uint32_t *arr, uint32_t arrSize, uint32_t *countArr, uint32_t kSize);

#endif /* CGGML_SORT_H */
