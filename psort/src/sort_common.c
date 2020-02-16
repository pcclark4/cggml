#include "sort_common.h"

/* https://rosettacode.org/wiki/Generic_swap#C */
void swap_bytes(void *va, void *vb, size_t s)
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

/* https://stackoverflow.com/a/1514309 */
int32_t int32_comparator_func(const void *left, const void *right)
{
    int32_t cmp;
    int32_t a = *(int32_t *) left;
    int32_t b = *(int32_t *) right;
    if ((b < 0) && (a > INT32_T_MAX + b)) { /* would overflow */
        cmp = 1;
    } else if ((b > 0) && (a < INT32_T_MIN + b)) { /* would underflow */
        cmp = -1;
    } else {
        cmp = a - b;
    }
    return cmp;
}
