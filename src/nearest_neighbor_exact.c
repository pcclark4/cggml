#include <stddef.h>

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    int searchSetSize, size_t elementSize,
    double (*distanceFunc)(const void *, const void *))
{
    const char *basePtr = searchSet;
    double leastDissimilar = -1.0;
    double currentDissimilar = 0.0;
    const void *nearestNeighbor = NULL;
    int i;

    for (i = 0; i < searchSetSize; i ++) {
        currentDissimilar = distanceFunc(query, basePtr);
        if (leastDissimilar == -1.0) {
            leastDissimilar = currentDissimilar;
            nearestNeighbor = basePtr;
        } else {
            if (currentDissimilar < leastDissimilar) {
                leastDissimilar = currentDissimilar;
                nearestNeighbor = basePtr;
            }
        }
        basePtr += elementSize;
    }
    return nearestNeighbor;
}
