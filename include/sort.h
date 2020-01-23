#ifndef CGGML_SORT_H
#define CGGML_SORT_H

#include "numerical_typedefs.h"
#include "stddef.h"

typedef int (*comparator)(const void *, const void *);

void sort_insertion(
    const void *arr, uint32_t arrSize, size_t elementSize, comparator cmp);

void sort_selection(
    const void *arr, uint32_t arrSize, size_t elementSize, comparator cmp);

void sort_bubble(
    const void *arr, uint32_t arrSize, size_t elementSize, comparator cmp);

#endif // CGGML_SORT_H
