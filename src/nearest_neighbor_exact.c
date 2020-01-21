#include <float.h>
#include <stddef.h>

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    unsigned int searchSetSize, size_t elementSize,
    double (*distanceFunc)(const void *, const void *))
{
    const char *basePtr = searchSet;
    const void *nearestNeighbor = NULL;
    double leastDistance = DBL_MAX;
    double currentDistance = 0.0;
    int i;

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
