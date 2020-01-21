#include "numerical_typedefs.h"
#include <stddef.h>

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    uint32_t searchSetSize, size_t elementSize,
    float64_t (*distanceFunc)(const void *, const void *))
{
    const int8_t *basePtr = searchSet;
    const void *nearestNeighbor = NULL;
    float64_t leastDistance = FLOAT64_MAX;
    float64_t currentDistance;
    uint32_t i;

    for (i = 0; i < searchSetSize; i++) {
        currentDistance = distanceFunc(query, basePtr);

        if (currentDistance < leastDistance) {
            leastDistance = currentDistance;
            nearestNeighbor = basePtr;
        }

        basePtr += elementSize;
    }

    return nearestNeighbor;
}
