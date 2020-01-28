#ifndef CGGML_NEAREST_NEIGHBOR_H
#define CGGML_NEAREST_NEIGHBOR_H

#include "numerical_typedefs.h"
#include <stddef.h>

typedef float64_t (*distance_func)(const void *, const void *);

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    uint32_t searchSetSize, size_t elementSize, distance_func dist);

void nearest_neighbor_exact_multi(const void *query, const void *searchSet,
    uint32_t searchSetSize, size_t elementSize, const void *neighbors,
    uint32_t numNeighbors, distance_func dist);

#endif // CGGML_NEAREST_NEIGHBOR_H
