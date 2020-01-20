#ifndef CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2D_H
#define CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2D_H

#include "point_2d.h"

const struct point_2d *nearest_neighbor_exact_point_2d(
    const struct point_2d *query, const struct point_2d *searchSet,
    int targetCount);

#endif // CGGML_NEAREST_NEIGHBOR_EXACT_POINT_2D_H
