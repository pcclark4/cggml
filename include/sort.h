#ifndef CGGML_SORT_H
#define CGGML_SORT_H

#include "numerical_typedefs.h"
#include "stddef.h"

typedef int32_t (*comparator_func)(const void *, const void *);
typedef int8_t (*equality_func)(const void *, const void *);

void sort_insertion(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp);

void sort_heap(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp);

#endif /* CGGML_SORT_H */
