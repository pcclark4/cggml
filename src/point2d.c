#include <math.h>
#include "point2d.h"

double distance2dSquared(const struct point2d* p1, const struct point2d* p2) {
    return (p2->x - p1->x)*(p2->x - p1->x) + (p2->y - p1->y)*(p2->y - p1->y);
}

double distance2d(const struct point2d* p1, const struct point2d* p2) {
    return sqrt(distance2dSquared(p1, p2));
}
