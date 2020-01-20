#include "nearest_neighbor_exact.h"
#include "point_2d.h"
#include <stdio.h>

enum { loop_size = 10000 };

int main(void) {
    unsigned int i = 0;
    double distance;
    const struct point_2d *nearestNeighbor = NULL;
    struct point_2d myPoint = {1.02, 1.01};
    struct point_2d myPoint2 = {3.0, 4.0};
    struct point_2d myPoints[5] = {
        {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}, {9.0, 10.0}};

    for (i = 0; i < loop_size; i++) {
        distance = point_2d_distance(&myPoint, &myPoint2);
    }

    nearestNeighbor = nearest_neighbor_exact(
        &myPoint2, (const void *) myPoints, 5, &point_2d_dissimilarity);
    printf("Nearest neighbor: { %f, %f }\n", nearestNeighbor->x,
        nearestNeighbor->y);

    printf("Done!");
    return 0;
}
