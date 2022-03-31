#include <ctest.h>
#include <libgeo/check.h>
#include <math.h>
#include <stdio.h>
#define size 128

CTEST(geometry_suite, simple_overlap)
{
    double x0 = 0, y0 = 0, r = 3, x1 = 0, y1 = 0, x2 = 2, y2 = 5, x3 = 5, 
 y3 = 0;
    float a, b, c;
    const int exp = 1;
    int res;
 a = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
 b = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2));
 c = sqrt((x0 - x3) * (x0 - x3) + (y0 - y3) * (y0 - y3));
    if (((a > r) && (b > r) && (b > r)) || ((a < r) && (b < r) && (c < r))) {
 res = 0;
        printf("Not overlap");
 } else {
 res = 1;
        printf("Overlap");
    }
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_not_overlap)
{
    double x0 = -, y0 = -33, r = 3, x1 = 4, y1 = 0, x2 = 5, y2 = 8, x3 = 6, 
 y3 = 0;
    float a, b, c;
    const int exp = 0;
    int res;
 a = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
 b = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2));
 c = sqrt((x0 - x3) * (x0 - x3) + (y0 - y3) * (y0 - y3));
    if (((a > r) && (b > r) && (b > r)) || ((a < r) && (b < r) && (c < r))) {
 res = 0;
        printf("Not overlap");
 } else {
 res = 1;
        printf("Overlap");
    }
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_circle_area)
{
    double r = 3, s;
    const int exp = 1;
    int res;

    if (r > 0) {
 s = M_PI * r * r;
        if (s > 27) {
 res = 1;
 } else {
 res = 0;
        }
    }
    ASSERT_EQUAL(exp, res);
}

CTEST(geometry_suite, simple_circle_perimetr)
{
    double r = 3, p;
    const int exp = 0;
    int res;

    if (r > 0) {
 p = M_PI * r * 2;
        if (p > 17) {
 res = 0;
 } else {
 res = 1;
        }
    }
    ASSERT_EQUAL(exp, res);
}
