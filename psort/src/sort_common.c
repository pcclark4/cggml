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
