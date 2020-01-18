#ifndef POINT2D_H
#define POINT2D_H

struct point2d {
    double x;
    double y;
};

double distance2dSquared(const struct point2d* p1, const struct point2d *p2);
double distance2d(const struct point2d* p1, const struct point2d* p2);

#endif
