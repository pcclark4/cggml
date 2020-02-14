#ifndef CGGML_SORT_RECURSIVE_H
#define CGGML_SORT_RECURSIVE_H

#include "sort_common.h"
#include <stddef.h>

/**
 * https://rosettacode.org/wiki/Sorting_algorithms/Quicksort#C
 * https://en.wikipedia.org/wiki/Quicksort
 *
 * Faster than heapsort. Not faster than radix sort.
 *
 * @param arr The array to be sorted
 * @param arrSize The size of the array
 * @param pivot A pointer to elementSize-bytes of space to hold the pivot value
 * @param elementSize The size of each element in bytes
 * @param cmp The comparison function pointer
 */
void sort_quick(void *arr, uint32_t arrSize, void *pivot, size_t elementSize,
    comparator_func cmp);

void sort_merge(void);

#endif /* CGGML_SORT_RECURSIVE_H */
