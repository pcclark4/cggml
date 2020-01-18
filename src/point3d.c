#include <math.h>
#include "point3d.h"

double distance3dSquared(const struct point3d* p1, const struct point3d* p2) {
    return (p2->x - p1->x)*(p2->x - p1->x) + (p2->y - p1->y)*(p2->y - p1->y) 
        + (p2->z - p1->z)*(p2->z - p1->z);
}

double distance3d(const struct point3d* p1, const struct point3d* p2) {
    return sqrt(distance3dSquared(p1, p2));
}
