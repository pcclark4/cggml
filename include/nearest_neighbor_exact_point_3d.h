#ifndef CGGML_NEAREST_NEIGHBOR_EXACT_POINT_3D_H
#define CGGML_NEAREST_NEIGHBOR_EXACT_POINT_3D_H

#include "point_3d.h"

const struct point_3d *nearest_neighbor_exact_point_3d(
    const struct point_3d *query, const struct point_3d *searchSet,
    int searchSetSize);

#endif // CGGML_NEAREST_NEIGHBOR_EXACT_POINT_3D_H
