#include "point_2d.h"
#include <math.h>

double point_2d_distance_squared(
    const struct point_2d *p1, const struct point_2d *p2)
{
    return (p2->x - p1->x) * (p2->x - p1->x) +
           (p2->y - p1->y) * (p2->y - p1->y);
}

double point_2d_distance(const struct point_2d *p1, const struct point_2d *p2)
{
    return sqrt(point_2d_distance_squared(p1, p2));
}
