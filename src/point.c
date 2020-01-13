#include <math.h>
#include "point.h"

double distSqRaw(double x1, double y1, double x2, double y2) {
    return (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
}

double distSq(point_2d *point1, point_2d *point2) {
    return distSqRaw(point1->x, point1->y, point2->x, point2->y);
}

double distRaw(double x1, double y1, double x2, double y2) {
    return sqrt(distSqRaw(x1, y1, x2, y2));
}

double dist(point_2d *point1, point_2d *point2) {
    return distRaw(point1->x, point1->y, point2->x, point2->y);
}
