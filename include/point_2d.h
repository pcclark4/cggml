#ifndef CGGML_POINT2D_H
#define CGGML_POINT2D_H

#include "numerical_typedefs.h"

struct point_2d
{
    float64_t x;
    float64_t y;
};

float64_t point_2d_distance_squared(
    const struct point_2d *p1, const struct point_2d *p2);

float64_t point_2d_distance(
    const struct point_2d *p1, const struct point_2d *p2);

#endif /* CGGML_POINT2D_H */
