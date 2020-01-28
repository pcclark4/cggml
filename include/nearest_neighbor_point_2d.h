#ifndef CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2D_H
#define CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2D_H

#include "point_2d.h"

const struct point_2d *nearest_neighbor_exact_point_2d(
    const struct point_2d *query, const struct point_2d *searchSet,
    uint32_t searchSetSize);

void nearest_neighbor_exact_point_2d_multi(const struct point_2d *query,
    const struct point_2d *searchSet, uint32_t searchSetSize,
    const struct point_2d *neighbors, uint32_t numNeighbors);

#endif // CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2D_H
