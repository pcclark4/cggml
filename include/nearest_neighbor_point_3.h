#ifndef CGGML_NEAREST_NEIGHBOR_EXACT_POINT_3_H
#define CGGML_NEAREST_NEIGHBOR_EXACT_POINT_3_H

#include "point_3.h"

const struct point_3 *nearest_neighbor_exact_point_3(
    const struct point_3 *query, const struct point_3 *searchSet,
    uint32_t searchSetSize);

void nearest_neighbors_exact_point_3_multi(const struct point_3 *query,
    const struct point_3 *searchSet, uint32_t searchSetSize,
    const struct point_3 *neighbors, uint32_t numNeighbors);

#endif /* CGGML_NEAREST_NEIGHBOR_EXACT_POINT_3_H */
