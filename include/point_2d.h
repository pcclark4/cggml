#ifndef CGGML_POINT2D_H
#define CGGML_POINT2D_H

struct point_2d
{
    double x;
    double y;
};

double point_2d_distance_squared(
    const struct point_2d *p1, const struct point_2d *p2);

double point_2d_distance(const struct point_2d *p1, const struct point_2d *p2);

#endif
