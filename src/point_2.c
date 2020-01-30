#include "point_2.h"
#include <math.h>

float64_t point_2_distance_squared(
    const struct point_2 *p1, const struct point_2 *p2)
{
    return (p2->x - p1->x) * (p2->x - p1->x) +
           (p2->y - p1->y) * (p2->y - p1->y);
}

float64_t point_2_distance(
    const struct point_2 *p1, const struct point_2 *p2)
{
    return sqrt(point_2_distance_squared(p1, p2));
}
