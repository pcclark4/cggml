#include "point_3.h"
#include <math.h>

float64_t point_3_distance_squared(
    const struct point_3 *p1, const struct point_3 *p2)
{
    return (p2->x - p1->x) * (p2->x - p1->x) +
           (p2->y - p1->y) * (p2->y - p1->y) +
           (p2->z - p1->z) * (p2->z - p1->z);
}

float64_t point_3_distance(const struct point_3 *p1, const struct point_3 *p2)
{
    return sqrt(point_3_distance_squared(p1, p2));
}
