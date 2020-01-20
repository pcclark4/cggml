#include "nearest_neighbor_exact.h"

const void *nearest_neighbor_exact(const void *query, const void *searchSet,
    int searchSetSize,
    double (*dissimilarityFunc)(const void *, const void *)) {
    double leastDissimilar = -1.0;
    double currentDissimilar = 0.0;
    const void *nearestNeighbor;
    int i;
    for (i = 0; i < searchSetSize; i++) {
        currentDissimilar = dissimilarityFunc(query, &searchSet[i]);
        if (leastDissimilar == -1.0) {
            leastDissimilar = currentDissimilar;
            nearestNeighbor = &searchSet[i];
        } else {
            if (currentDissimilar < leastDissimilar) {
                leastDissimilar = currentDissimilar;
                nearestNeighbor = &searchSet[i];
            }
        }
    }
    return nearestNeighbor;
}
