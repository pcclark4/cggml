#include "sort.h"
#include <string.h>

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
            swap_bytes(left, right, elementSize);
        }
    }
}

/* Astonishingly low number of writes, but holy moly it is much slower than
 * insertion sort. Only use if you must. It does a ton of comparisons. */
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

        swap_bytes(tmp, iterator + pos * elementSize, elementSize);

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

            swap_bytes(tmp, iterator + pos * elementSize, elementSize);
        }
    }
}

/* Convenience macros for heap sort to make it more readable */
#define LESS_THAN(I, J)                                                        \
    cmp(iterator + (I) *elementSize, iterator + (J) *elementSize) < 0

#define SWAP(I, J)                                                             \
    swap_bytes(iterator + (I) *elementSize, iterator + (J) *elementSize, elementSize)

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

void sort_counting_generic(const void *inputArr, void *outputArr,
    uint32_t arrSize, size_t eleSize, keygen_func key, uint32_t *countArr,
    uint32_t minKey, uint32_t maxKey)
{
    const uint8_t *input = inputArr;
    uint8_t *output = outputArr;
    const uint8_t *currentInput;
    uint32_t currentKey;
    uint32_t i;

    for (i = 0; i < arrSize; i++) {
        countArr[key(input + i * eleSize) - minKey]++;
    }

    for (i = 1; i <= maxKey - minKey; i++) {
        countArr[i] += countArr[i - 1];
    }

    for (i = arrSize; i > 0; i--) {
        currentInput = input + (i - 1) * eleSize;
        currentKey = key(currentInput) - minKey;
        countArr[currentKey]--;
        memcpy(output + countArr[currentKey] * eleSize, currentInput, eleSize);
    }
}

void sort_counting_uint32(uint32_t *arr, uint32_t arrSize, uint32_t *countArr,
    uint32_t minKey, uint32_t maxKey)
{
    uint32_t i;
    uint32_t j;
    uint32_t k;

    for (i = 0; i < arrSize; i++) {
        countArr[arr[i] - minKey]++;
    }

    k = 0;
    for (i = 0; i <= maxKey - minKey; i++) {
        for (j = 0; j < countArr[i]; j++) {
            arr[k] = i + minKey;
            k++;
        }
    }
}

#define NUM_BITS 32

void sort_radix_lsd_uint32_bitwise(
    uint32_t *arr, uint32_t *aux, uint32_t arrSize)
{
    uint32_t count[2];
    uint32_t i;
    uint32_t j;
    uint32_t currentKey;

    for (i = 0; i < NUM_BITS; i++) {
        count[0] = 0;
        count[1] = 0;

        for (j = 0; j < arrSize; j++) {
            /* arr[j] >> i will shift the 32-bit uint over i-bytes
             * the bitwise AND (& 1u) operation returns the value of the bit
             * in the right-most position. We are slowly creeping up the
             * bits of the number. */
            count[(arr[j] >> i) & 1u]++;
        }

        for (j = 1; j < 2; j++) {
            count[j] += count[j - 1];
        }

        for (j = arrSize; j > 0; j--) {
            currentKey = (arr[j - 1] >> i) & 1u;
            count[currentKey]--;
            aux[count[currentKey]] = arr[j - 1];
        }

        memcpy(arr, aux, sizeof(uint32_t) * arrSize);
    }
}

#undef NUM_BITS

#define NUM_BYTES 4
#define BITS_PER_BYTE 8
#define COUNT_SIZE 256
#define MASK 0xFFu

/* This is actually about 9-10x faster than the per-bit version! Wrote the func
 * in a short-as-possible, obfuscating style code that everyone hates, just for
 * fun :). */
void sort_radix_lsd_uint32_bytewise(
    uint32_t *arr, uint32_t *aux, uint32_t arrSize)
{
    uint32_t c[COUNT_SIZE], i, j;
    for (i = 0; i < NUM_BYTES; i++) {
        memset(c, 0u, sizeof(uint32_t) * COUNT_SIZE);
        for (j = 0; j < arrSize; j++) {
            c[(arr[j] >> (i * BITS_PER_BYTE)) & MASK]++;
        }
        for (j = 1; j < COUNT_SIZE; j++) {
            c[j] += c[j - 1];
        }
        for (j = arrSize; j > 0; j--) {
            aux[--c[(arr[j - 1] >> (i * BITS_PER_BYTE)) & MASK]] = arr[j - 1];
        }
        memcpy(arr, aux, sizeof(uint32_t) * arrSize);
    }
}

static void sort_radix_lsd_float32_bytewise(
    float32_t *arr, float32_t *aux, uint32_t arrSize)
{}

#undef NUM_BYTES
#undef BITS_PER_BYTE
#undef COUNT_SIZE
#undef MASK
