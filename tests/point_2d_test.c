#include "point_2d.h"
#include <check.h>
#include <stdio.h>
#include <stdlib.h>

START_TEST(point_2d_distance_squared_test)
{
    ck_assert_int_eq(3, 4);
}
END_TEST

START_TEST(point_2d_distance_test)
{

}
END_TEST

int main(void)
{
    struct point_2d myPoint = { 1.0, -1.0 };
    printf("{ %f, %f }", myPoint.x, myPoint.y);
    return 0;
}
