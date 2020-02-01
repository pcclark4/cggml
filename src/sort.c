#include "sort.h"
#include <stdlib.h>
#include <string.h>

/* https://rosettacode.org/wiki/Generic_swap#C */
/* Might want to move this out to a header file somewhere */
static void swap(void *va, void *vb, size_t s)
{
    int8_t tmp;
    int8_t *a = va;
    int8_t *b = vb;

    while (s > 0) {
        s = s - 1;
        tmp = a[s];
        a[s] = b[s];
        b[s] = tmp;
    }
}

void sort_insertion(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp)
{
    int8_t *iterator = arr;
    void *left;
    void *right;
    uint32_t i;
    uint32_t j;

    for (i = 1; i < arrSize; i++) {
        for (j = i; j > 0; j--) {
            left = iterator + (j - 1) * elementSize;
            right = iterator + j * elementSize;
            if (cmp(left, right) <= 0) {
                break;
            }
            swap(left, right, elementSize);
        }
    }
}

void sort_cycle(void *arr, uint32_t arrSize, size_t elementSize,
    comparator_func cmp, void *tmp)
{
    int8_t *iterator = arr;
    uint32_t cycleStart;
    uint32_t j;
    uint32_t pos;

    for (cycleStart = 0; cycleStart < arrSize - 1; cycleStart++) {
        memcpy(tmp, iterator + cycleStart * elementSize, elementSize);

        pos = cycleStart;
        for (j = cycleStart + 1; j < arrSize; j++) {
            if (cmp(iterator + j * elementSize, tmp) < 0) {
                pos++;
            }
        }

        if (pos == cycleStart) {
            continue;
        }

        while (cmp(tmp, iterator + pos * elementSize) == 0) {
            pos++;
        }

        swap(tmp, iterator + pos * elementSize, elementSize);

        while (pos != cycleStart) {
            pos = cycleStart;
            for (j = cycleStart + 1; j < arrSize; j++) {
                if (cmp(iterator + j * elementSize, tmp) < 0) {
                    pos++;
                }
            }

            while (cmp(tmp, iterator + pos * elementSize) == 0) {
                pos++;
            }

            swap(tmp, iterator + pos * elementSize, elementSize);
        }
    }
}

#define LESS_THAN(I, J, ITERATOR, ELE_SIZE)                                    \
    cmp(ITERATOR + (I) * (ELE_SIZE), ITERATOR + (J) * (ELE_SIZE)) < 0

#define SWAP(I, J, ITERATOR, ELE_SIZE)                                         \
    swap(ITERATOR + (I) * (ELE_SIZE), ITERATOR + (J) * (ELE_SIZE), ELE_SIZE)

static void sift_down(void *arr, uint32_t start, uint32_t end,
    size_t elementSize, comparator_func cmp)
{
    int8_t *iterator = arr;
    uint32_t child;

    while ((start * 2 + 1) <= end) {
        child = start * 2 + 1;

        if (child < end && LESS_THAN(child, child + 1, iterator, elementSize)) {
            child++;
        }

        if (LESS_THAN(start, child, iterator, elementSize)) {
            SWAP(start, child, iterator, elementSize);
            start = child;
        } else {
            break;
        }
    }
}

static void heapify(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp)
{
    uint32_t start;

    for (start = (arrSize - 1) / 2; start != 0; start--) {
        sift_down(arr, start - 1, arrSize - 1, elementSize, cmp);
    }
}

void sort_heap(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp)
{
    int8_t *iterator = arr;
    uint32_t end = arrSize - 1;

    heapify(arr, arrSize, elementSize, cmp);

    while (end > 0) {
        SWAP(end, 0, iterator, elementSize);
        sift_down(arr, 0, end - 1, elementSize, cmp);
        end--;
    }
}

#undef SWAP
#undef LESS_THAN
