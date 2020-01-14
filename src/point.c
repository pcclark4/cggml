#include <math.h>
#include "point.h"

double distance2dSquaredRaw(double x1, double y1, double x2, double y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

double distance2dSquared(struct point2d *p1, struct point2d *p2) {
    return distance2dSquaredRaw(p1->x, p1->y, p2->x, p2->y);
}

double distance2dRaw(double x1, double y1, double x2, double y2) {
    return sqrt(distance2dSquaredRaw(x1, y1, x2, y2));
}

double distance2d(struct point2d *p1, struct point2d *p2) {
    return distance2dRaw(p1->x, p1->y, p2->x, p2->y);
}

double distance3dSquaredRaw(double x1, double y1, double z1, double x2, double y2, double z2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1) + (z2-z1)*(z2-z1);
}

double distance3dSquared(struct point3d *p1, struct point3d *p2) {
    return distance3dSquaredRaw(p1->x, p1->y, p1->z, p2->x, p2->y, p2->z);
}

double distance3dRaw(double x1, double y1, double z1, double x2, double y2, double z2) {
    return sqrt(distance3dSquaredRaw(x1, y1, z1, x2, y2, z2));
}

double distance3d(struct point3d *p1, struct point3d *p2) {
    return distance3dRaw(p1->x, p1->y, p1->z, p2->x, p2->y, p2->z);
}

