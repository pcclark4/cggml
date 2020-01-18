#ifndef POINT3D_H
#define POINT3D_H

struct point3d {
    double x;
    double y;
    double z;
};

double distance3dSquared(const struct point3d* p1, const struct point3d* p2);
double distance3d(const struct point3d* p1, const struct point3d* p2);

#endif
