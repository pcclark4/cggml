#include "point_3d.h"
#include <math.h>

double point_3d_distance_squared(
    const struct point_3d *p1, const struct point_3d *p2) {
    return (p2->x - p1->x) * (p2->x - p1->x) +
           (p2->y - p1->y) * (p2->y - p1->y) +
           (p2->z - p1->z) * (p2->z - p1->z);
}

double point_3d_distance(const struct point_3d *p1, const struct point_3d *p2) {
    return sqrt(point_3d_distance_squared(p1, p2));
}
