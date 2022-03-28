#include "libgeo/check.h"
#include "libgeo/circle.h"
#include "libgeo/triangle.h"
#include <math.h>
#include <stdio.h>

int main()
{
    double x0, y0, r, x1, y1, x2, y2, x3, y3;
    printf("Enter (x y rad) for circle\n");
    scanf("%lf %lf %lf", &x0, &y0, &r);
    if (r < 0) {
        printf("Error");
        return 1;
    }
    printf("Enter (x1 y1) for triangle\n");
    scanf("%lf %lf", &x1, &y1);
    printf("Enter (x2 y2) for triangle\n");
    scanf("%lf %lf", &x2, &y2);
    printf("Enter (x3 y3) for triangle\n");
    scanf("%lf %lf", &x3, &y3);
    circle(r);
    triangle(x1, y1, x2, y2, x3, y3);
    check(x0, y0, r, x1, y1, x2, y2, x3, y3);
    return 0;
}
