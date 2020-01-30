#include "sort.h"
#include <stdio.h>
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

/* Extremely fast for small array sizes
 * https://en.wikipedia.org/wiki/Insertion_sort */
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
void sort_heap(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp)
{

}
