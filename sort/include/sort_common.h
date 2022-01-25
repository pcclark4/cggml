#ifndef CGGML_SORT_COMMON_H
#define CGGML_SORT_COMMON_H

#include "numerical_typedefs.h"
#include <stddef.h>

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

void swap_bytes(void *va, void *vb, size_t s);
int32_t int32_comparator_func(const void *left, const void *right);

#endif /* CGGML_SORT_COMMON_H */
