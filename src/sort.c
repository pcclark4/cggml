#include "sort.h"
#include <stdlib.h>
#include <string.h>

/* https://rosettacode.org/wiki/Generic_swap#C */
/* Might want to move this out to a header file somewhere */
static void swap(void *va, void *vb, size_t s)
{
    uint8_t tmp;
    uint8_t *a = va;
    uint8_t *b = vb;

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
    uint8_t *iterator = arr;
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

/* Astonishingly low number of writes, but holy moly it is much slower than
 * insertion sort. Only use if you must. */
void sort_cycle(void *arr, uint32_t arrSize, size_t elementSize,
    comparator_func cmp, void *tmp)
{
    uint8_t *iterator = arr;
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

/* Convenience macros for heap sort to make it more readable */
#define LESS_THAN(I, J)                                                        \
    cmp(iterator + (I) *elementSize, iterator + (J) *elementSize) < 0

#define SWAP(I, J)                                                             \
    swap(iterator + (I) *elementSize, iterator + (J) *elementSize, elementSize)

static void sift_down(void *arr, uint32_t start, uint32_t end,
    size_t elementSize, comparator_func cmp)
{
    uint8_t *iterator = arr;
    uint32_t child;

    while ((start * 2 + 1) <= end) {
        child = start * 2 + 1;

        if (child < end && LESS_THAN(child, child + 1)) {
            child++;
        }

        if (LESS_THAN(start, child)) {
            SWAP(start, child);
            start = child;
        } else {
            break;
        }
    }
}

static void heapify(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp)
{
    /* Had to do some weirdness here due to start being unsigned */
    uint32_t start = (arrSize - 2) / 2;
    sift_down(arr, start, arrSize - 1, elementSize, cmp);
    if (start != 0) {
        do {
            start--;
            sift_down(arr, start, arrSize - 1, elementSize, cmp);
        } while (start != 0);
    }
}

void sort_heap(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp)
{
    if (arrSize > 1) {
        uint8_t *iterator = arr;
        uint32_t end = arrSize - 1;

        heapify(arr, arrSize, elementSize, cmp);

        while (end > 0) {
            SWAP(end, 0);
            sift_down(arr, 0, end - 1, elementSize, cmp);
            end--;
        }
    }
}

#undef SWAP
#undef LESS_THAN

void sort_counting(const void *inputArr, void *outputArr, uint32_t arrSize,
    size_t eleSize, keygen_func key, uint32_t *countArr, uint32_t maxKey)
{
    const uint8_t *input = inputArr;
    uint8_t *output = outputArr;
    const uint8_t *currentInput;
    uint32_t currentKey;
    uint32_t i;

    for (i = 0; i < arrSize; i++) {
        countArr[key(input + i * eleSize)]++;
    }

    for (i = 1; i <= maxKey; i++) {
        countArr[i] += countArr[i - 1];
    }

    for (i = arrSize; i > 0; i--) {
        currentInput = input + (i - 1) * eleSize;
        currentKey = key(currentInput);
        countArr[currentKey]--;
        memcpy(output + countArr[currentKey] * eleSize, currentInput, eleSize);
    }
}

/* https://opendatastructures.org/ods-java/11_2_Counting_Sort_Radix_So.html
 * Unstable but uses N less memory, which could be good for some situations */
void sort_counting_unstable(void *inputArr, uint32_t arrSize, size_t eleSize,
    keygen_func key, uint32_t *countArr, uint32_t maxKey)
{
    uint8_t *input = inputArr;
    uint8_t *currentInput;
    uint32_t currentKey;
    uint32_t tmpCount;
    uint32_t i;
    uint32_t total = 0;

    for (i = 0; i < arrSize; i++) {
        countArr[key(input + i * eleSize)]++;
    }

    for (i = 0; i <= maxKey; i++) {
        tmpCount = countArr[i];
        countArr[i] = total;
        total += tmpCount;
    }

    for (i = 0; i < arrSize; i++) {
        currentInput = input + i * eleSize;
        currentKey = key(currentInput);
        if (i != countArr[currentKey]) {
            swap(currentInput, input + countArr[currentKey] * eleSize, eleSize);
            currentKey = key(currentInput);
            if (i == countArr[currentKey]) {
                i++;
            }
            countArr[currentKey]++;
        }
    }
}

void sort_counting_uint32(
    uint32_t *arr, uint32_t arrSize, uint32_t *countArr, uint32_t maxKey)
{
    uint32_t i;
    uint32_t j;
    uint32_t k;

    for (i = 0; i < arrSize; i++) {
        countArr[arr[i]]++;
    }

    k = 0;
    for (i = 0; i < maxKey; i++) {
        for (j = 0; j < countArr[i]; j++) {
            arr[k] = i;
            k++;
        }
    }
}
