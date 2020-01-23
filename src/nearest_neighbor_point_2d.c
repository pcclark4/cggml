#include "nearest_neighbor_point_2d.h"
#include "nearest_neighbor.h"
#include "point_2d.h"

static float64_t point_2d_distance_func(const void *p1, const void *p2)
{
    return point_2d_distance_squared(p1, p2);
}

const struct point_2d *nearest_neighbor_exact_point_2d(
    const struct point_2d *query, const struct point_2d *searchSet,
    uint32_t searchSetSize)
{
    return nearest_neighbor_exact(query, searchSet, searchSetSize,
        sizeof(struct point_2d), &point_2d_distance_func);
}

void nearest_neighbor_exact_point_2d_multi(const struct point_2d *query,
    const struct point_2d *searchSet, uint32_t searchSetSize,
    const struct point_2d **neighbors, uint32_t numNeighbors)
{
    nearest_neighbor_exact_multi(query, searchSet, searchSetSize,
        sizeof(struct point_2d), neighbors, numNeighbors,
        &point_2d_distance_func);
}
