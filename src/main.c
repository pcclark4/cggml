#include "nearest_neighbor_exact_point_2d.h"
#include "point_2d.h"
#include <stdio.h>
#include <stdlib.h>

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

    struct point_2d myBigPoints[100] = {0};
    for (i = 0; i < 100; i++) {
        myPoint.x = i;
        myPoint.y = i + 1;
        myBigPoints[i] = myPoint;
    }

    for (i = 0; i < loop_size; i++) {
        nearestNeighbor =
            nearest_neighbor_exact_point_2d(&myPoint2, myBigPoints, 100);
    }
    printf("Nearest neighbor: { %f, %f }\n", nearestNeighbor->x,
        nearestNeighbor->y);

    printf("Done!");
    return 0;
}
