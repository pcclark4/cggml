#include "nearest_neighbor_exact.h"
#include "nearest_neighbor_exact_point_2d.h"
#include "point_2d.h"
#include <stdio.h>

enum
{
    loop_size = 32000
};

int main(void)
{
    unsigned int i = 0;
    const struct point_2d *nearestNeighbor = NULL;
    struct point_2d myPoint = {1.02, 1.01};
    struct point_2d myPoint2 = {7.0, 4.0};
    struct point_2d myPoints[5] = {
        {1.0, 2.0}, {3.0, 4.0}, {5.0, 6.0}, {7.0, 8.0}, {9.0, 10.0}};

    for (i = 0; i < loop_size; i++) {
        nearestNeighbor =
            nearest_neighbor_exact_point_2d(&myPoint2, myPoints, 5);
    }
    printf("Nearest neighbor: { %f, %f }\n", nearestNeighbor->x,
        nearestNeighbor->y);

    printf("Done!");
    return 0;
}
