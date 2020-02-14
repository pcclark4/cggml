#include "sort_recursive.h"
#include "sort.h"
#include <string.h>

void sort_quick(void *arr, uint32_t arrSize, void *pivot, size_t elementSize,
    comparator_func cmp)
{
    uint8_t *iterator;
    uint32_t i, j;

    if (arrSize > 1u) {
        if (arrSize < 16u) {
            sort_insertion(arr, arrSize, elementSize, cmp);
        } else {
            iterator = arr;
            memcpy(pivot, iterator + (arrSize / 2u) * elementSize, elementSize);
            for (i = 0u, j = arrSize - 1u;; i++, j--) {
                while (cmp(iterator + i * elementSize, pivot) < 0) {
                    i++;
                }
                while (cmp(iterator + j * elementSize, pivot) > 0) {
                    j--;
                }
                if (i >= j) {
                    break;
                }
                swap_bytes(iterator + i * elementSize,
                    iterator + j * elementSize, elementSize);
            }
            sort_quick(iterator, i, pivot, elementSize, cmp);
            sort_quick(iterator + i * elementSize, arrSize - i, pivot,
                elementSize, cmp);
        }
    }
}
