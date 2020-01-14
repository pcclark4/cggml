#ifndef POINT_H
#define POINT_H

struct point2d {
    double x;
    double y;
};

struct point3d {
    double x;
    double y;
    double z;
};

double distance2dSquaredRaw(double x1, double y1, double x2, double y2);
double distance2dSquared(struct point2d *p1, struct point2d *p2);
double distance2dRaw(double x1, double y1, double x2, double y2);
double distance2d(struct point2d *p1, struct point2d *p2);

double distance3dSquaredRaw(double x1, double y1, double z1, double x2, double y2, double z2);
double distance3dSquared(struct point3d *p1, struct point3d *p2);
double distance3dRaw(double x1, double y1, double z1, double x2, double y2, double z2);
double distance3d(struct point3d *p1, struct point3d *p2);

#endif
