typedef struct point_2d {
    double x;
    double y;
} point_2d;

typedef struct point_3d {
    double x;
    double y;
    double z;
} point_3d;

double distSqRaw(double x1, double y1, double x2, double y2);
double distSq(point_2d *point1, point_2d *point2);

double distRaw(double x1, double y1, double x2, double y2);
double dist(point_2d *point1, point_2d *point2);
