#include <stdio.h>
#include "point.h"

enum { loop_size = 10000 };

int main(void) {
    unsigned int i = 0;
    double distance;
    struct point2d myPoint = { 1.02, 1.01 };
    struct point2d myPoint2 = { 3.044, 40.55 };

    for (i = 0; i < loop_size; i++) {
        distance = distance2dRaw(i, 2.0, -i, 98.44533);
        distance = distance2d(&myPoint, &myPoint2);
    }

    printf("Done!");
    return 0;
}
