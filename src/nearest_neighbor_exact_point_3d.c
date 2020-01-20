#include "nearest_neighbor_exact_point_3d.h"
#include "nearest_neighbor_exact.h"

static double nearest_neighbor_exact_point_3d_dissimilarity(
    const void *p1, const void *p2)
{
    return point_3d_distance_squared(p1, p2);
}

const struct point_3d *nearest_neighbor_exact_point_3d(
    const struct point_3d *query, const struct point_3d *searchSet,
    int targetCount)
{
    return nearest_neighbor_exact(query, searchSet, targetCount,
        sizeof(struct point_3d),
        &nearest_neighbor_exact_point_3d_dissimilarity);
}
