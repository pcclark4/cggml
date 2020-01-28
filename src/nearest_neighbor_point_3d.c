#include "nearest_neighbor_point_3d.h"
#include "nearest_neighbor.h"
#include "point_3d.h"

static float64_t point_3d_distance_func(const void *p1, const void *p2)
{
    return point_3d_distance_squared(p1, p2);
}

const struct point_3d *nearest_neighbor_exact_point_3d(
    const struct point_3d *query, const struct point_3d *searchSet,
    uint32_t searchSetSize)
{
    return nearest_neighbor_exact(query, searchSet, searchSetSize,
        sizeof(struct point_3d), &point_3d_distance_func);
}

void nearest_neighbors_exact_point_3d_multi(const struct point_3d *query,
    const struct point_3d *searchSet, uint32_t searchSetSize,
    const struct point_3d *neighbors, uint32_t numNeighbors)
{
    nearest_neighbor_exact_multi(query, searchSet, searchSetSize,
        sizeof(struct point_3d), neighbors, numNeighbors,
        &point_3d_distance_func);
}
