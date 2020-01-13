#include <stdio.h>
#include "point.h"

enum { loop_size = 10000 };

int main(void) {
    unsigned int i = 0;
    double distance;
    long long int test = 0l;
    for (i = 0; i < loop_size; i++) {
        distance = distRaw(i, 2.0, -i, 98.44533);
        
    }
    printf("Done!");
    return 0;
}
