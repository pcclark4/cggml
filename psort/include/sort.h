#ifndef CGGML_SORT_H
#define CGGML_SORT_H

#include "numerical_typedefs.h"
#include "stddef.h"

/** Function pointer that represents a comparison done on two objects
 * @returns Zero if the items are equal, a positive integer if a is greater than
 * b, a negative integer if a is less than b
 */
typedef int32_t (*comparator_func)(const void *a, const void *b);

/** Used in counting (and possibly? radix) sort.
 * @param obj The object to generate a key for
 * @returns A nonnegative key representation of obj
 */
typedef uint32_t (*keygen_func)(const void *obj);

/** Extremely fast for small array sizes
 * https://en.wikipedia.org/wiki/Insertion_sort
 *
 * @param arr The array to be sorted
 * @param arrSize The size of the array
 * @param elementSize The size of each element in bytes
 * @param cmp The function used to determine element order
 */
void sort_insertion(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp);

/** Efficient in environments where writes are extremely expensive (flash mem)
 * https://en.wikipedia.org/wiki/Cycle_sort
 * Caller must pass an extra elementSize-bytes to hold temporary value
 * necessary for the algorithm
 *
 * @param arr The array to be sorted
 * @param arrSize The size of the array
 * @param elementSize The size of each element in bytes
 * @param cmp The function used to determine element order
 * @param tmp A pointer to elementSize-bytes of space
 */
void sort_cycle(void *arr, uint32_t arrSize, size_t elementSize,
    comparator_func cmp, void *tmp);

/** Fastest for larger data sets
 * https://en.wikipedia.org/wiki/Heapsort
 * https://rosettacode.org/wiki/Sorting_algorithms/Heapsort#C
 *
 * @param arr The array to be sorted
 * @param arrSize The size of the array
 * @param elementSize The size of each element in bytes
 * @param cmp The function used to determine element order
 */
void sort_heap(
    void *arr, uint32_t arrSize, size_t elementSize, comparator_func cmp);

/** O(n + k) performance
 * https://en.wikipedia.org/wiki/Counting_sort
 * https://medium.com/basecs/counting-linearly-with-counting-sort-cd8516ae09b3
 * Only practical in situations where the variation in keys is not significantly
 * greater than the number of items. Often used as a subroutine in radix sort.
 *
 * In other words, it is usually not used unless N is larger than K.
 *
 * @param inputArr The array containing the values to be sorted
 * @param outputArr An array of the same size as inputArr to be used to hold the
 * finished sorted items
 * @param arrSize The size of the array
 * @param eleSize The size of each element in bytes
 * @param key Function used to generate a nonnegative integer key for each item
 * @param countArr A zero'd out array of size maxKey + 1
 * @param maxKey The maximum key value present in the input data set
 */
void sort_counting(const void *inputArr, void *outputArr, uint32_t arrSize,
    size_t eleSize, keygen_func key, uint32_t *countArr, uint32_t minKey,
    uint32_t maxKey);

/* In-place and for uint32's only */
void sort_counting_uint32(uint32_t *arr, uint32_t arrSize, uint32_t *countArr,
    uint32_t minKey, uint32_t maxKey);

/** https://en.wikipedia.org/wiki/Radix_sort
 * https://algs4.cs.princeton.edu/51radix/LSD.java.html
 * https://opendatastructures.org/ods-java/11_2_Counting_Sort_Radix_So.html
 *
 * @param arr The array to be sorted
 * @param aux An array of the same size and type as arr
 * @param arrSize The size of the array
 */
void sort_radix_lsd_uint32(uint32_t *arr, uint32_t *aux, uint32_t arrSize);

#endif /* CGGML_SORT_H */
