#include <stdio.h>
#include "point.h"

enum { loop_size = 10000 };

int main(void) {
    unsigned int i = 0;
    double distance;
    point_2d myPoint = { 1.0, 1.0 };
    point_3d my3dPoint = { 1.0, 1.0, 1.00020320302032 };
    for (i = 0; i < loop_size; i++) {
        distance = distRaw(i, 2.0, -i, 98.44533);
        
    }
    printf("Done!");
    return 0;
}
