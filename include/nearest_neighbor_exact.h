#ifndef CGGML_NEAREST_NEIGHBOR_EXACT_H
#define CGGML_NEAREST_NEIGHBOR_EXACT_H

#include <stddef.h>

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    unsigned int searchSetSize, size_t elementSize,
    double (*distanceFunc)(const void *, const void *));

#endif // CGGML_NEAREST_NEIGHBOR_EXACT_H
