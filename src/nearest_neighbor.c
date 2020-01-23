#include "nearest_neighbor.h"
#include "numerical_typedefs.h"
#include <stddef.h>

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    uint32_t searchSetSize, size_t elementSize, distance_func dist)
{
    const int8_t *iterator = searchSet;
    const void *nearestNeighbor = NULL;
    float64_t leastDistance = FLOAT64_MAX;
    float64_t currentDistance;
    uint32_t i;

    for (i = 0; i < searchSetSize; i++) {
        currentDistance = dist(query, iterator);

        if (currentDistance < leastDistance) {
            leastDistance = currentDistance;
            nearestNeighbor = iterator;
        }

        iterator += elementSize;
    }

    return nearestNeighbor;
}

void nearest_neighbor_exact_multi(const void *query, const void *searchSet,
    uint32_t searchSetSize, size_t elementSize, const void **neighbors,
    uint32_t numNeighbors, distance_func dist)
{
    /* numNeighbors must be <= searchSetSize */
    const int8_t *iterator = searchSet;
    float64_t currentDistance;
    float64_t rightDistance;
    uint32_t i;

    for (i = 0; i < numNeighbors; i++) {
    }

    for (i = 0; i < searchSetSize; i++) {
        currentDistance = dist(query, iterator);

        iterator += elementSize;
    }
}
