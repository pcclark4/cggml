#include "nearest_neighbor_exact.h"
#include "point_2d.h"

static float64_t nearest_neighbor_exact_point_2d_dissimilarity(
    const void *p1, const void *p2)
{
    return point_2d_distance_squared(p1, p2);
}

const struct point_2d *nearest_neighbor_exact_point_2d(
    const struct point_2d *query, const struct point_2d *searchSet,
    uint32_t searchSetSize)
{
    return nearest_neighbor_exact(query, searchSet, searchSetSize,
        sizeof(struct point_2d),
        &nearest_neighbor_exact_point_2d_dissimilarity);
}
