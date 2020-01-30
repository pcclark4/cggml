#include "nearest_neighbor_point_3.h"
#include "nearest_neighbor.h"
#include "point_3.h"

static float64_t point_3_distance_func(const void *p1, const void *p2)
{
    return point_3_distance_squared(p1, p2);
}

const struct point_3 *nearest_neighbor_exact_point_3(
    const struct point_3 *query, const struct point_3 *searchSet,
    uint32_t searchSetSize)
{
    return nearest_neighbor_exact(query, searchSet, searchSetSize,
        sizeof(struct point_3), &point_3_distance_func);
}

void nearest_neighbors_exact_point_3_multi(const struct point_3 *query,
    const struct point_3 *searchSet, uint32_t searchSetSize,
    const struct point_3 *neighbors, uint32_t numNeighbors)
{
    nearest_neighbor_exact_multi(query, searchSet, searchSetSize,
        sizeof(struct point_3), neighbors, numNeighbors,
        &point_3_distance_func);
}
