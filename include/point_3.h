#ifndef CGGML_POINT3D_H
#define CGGML_POINT3D_H

#include "numerical_typedefs.h"

struct point_3
{
    float64_t x;
    float64_t y;
    float64_t z;
};

float64_t point_3_distance_squared(
    const struct point_3 *p1, const struct point_3 *p2);

float64_t point_3_distance(
    const struct point_3 *p1, const struct point_3 *p2);

#endif /* CGGML_POINT3D_H */
