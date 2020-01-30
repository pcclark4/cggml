#include "nearest_neighbor_point_2.h"
#include "nearest_neighbor.h"
#include "point_2.h"

static float64_t point_2_distance_func(const void *p1, const void *p2)
{
    return point_2_distance_squared(p1, p2);
}

const struct point_2 *nearest_neighbor_exact_point_2(
    const struct point_2 *query, const struct point_2 *searchSet,
    uint32_t searchSetSize)
{
    return nearest_neighbor_exact(query, searchSet, searchSetSize,
        sizeof(struct point_2), &point_2_distance_func);
}

void nearest_neighbor_exact_point_2_multi(const struct point_2 *query,
    const struct point_2 *searchSet, uint32_t searchSetSize,
    const struct point_2 *neighbors, uint32_t numNeighbors)
{
    nearest_neighbor_exact_multi(query, searchSet, searchSetSize,
        sizeof(struct point_2), neighbors, numNeighbors,
        &point_2_distance_func);
}
