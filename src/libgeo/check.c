#include "check.h"
#include <math.h>
#include <stdio.h>

int check(
        double x0,
        double y0,
        double r,
        double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3)
{
    float a, b, c;
    a = sqrt((x0 - x1) * (x0 - x1) + (y0 - y1) * (y0 - y1));
    b = sqrt((x0 - x2) * (x0 - x2) + (y0 - y2) * (y0 - y2));
    c = sqrt((x0 - x3) * (x0 - x3) + (y0 - y3) * (y0 - y3));
    if (((a > r) && (b > r) && (b > r)) || ((a < r) && (b < r) && (c < r))) {
        printf("don 't overlap\n");
    } else {
        printf("overlap\n");
    }
    return 0;
}
