#ifndef POINT3D_H
#define POINT3D_H

struct point_3d {
    double x;
    double y;
    double z;
};

double point_3d_distance_squared(
    const struct point_3d *p1, const struct point_3d *p2);

double point_3d_distance(const struct point_3d *p1, const struct point_3d *p2);

#endif
