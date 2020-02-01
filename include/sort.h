#ifndef CGGML_SORT_H
#define CGGML_SORT_H

#include "numerical_typedefs.h"
#include "stddef.h"

typedef int32_t (*comparator_func)(const void *, const void *);

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

#endif /* CGGML_SORT_H */
