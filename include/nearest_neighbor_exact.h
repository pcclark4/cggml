#ifndef CGGML_NEAREST_NEIGHBOR_EXACT_H
#define CGGML_NEAREST_NEIGHBOR_EXACT_H

#include "numerical_typedefs.h"
#include <stddef.h>

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    uint32_t searchSetSize, size_t elementSize,
    float64_t (*distanceFunc)(const void *, const void *));

#endif // CGGML_NEAREST_NEIGHBOR_EXACT_H
