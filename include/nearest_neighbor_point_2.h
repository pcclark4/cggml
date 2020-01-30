#ifndef CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2_H
#define CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2_H

#include "point_2.h"

const struct point_2 *nearest_neighbor_exact_point_2(
    const struct point_2 *query, const struct point_2 *searchSet,
    uint32_t searchSetSize);

void nearest_neighbor_exact_point_2_multi(const struct point_2 *query,
    const struct point_2 *searchSet, uint32_t searchSetSize,
    const struct point_2 *neighbors, uint32_t numNeighbors);

#endif /* CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2_H */
