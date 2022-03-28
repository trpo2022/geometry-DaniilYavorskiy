#include "triangle.h"
#include <math.h>
#include <stdio.h>

void triangle(
	double x1,
        double y1,
        double x2,
        double y2,
        double x3,
        double y3)
{
    float a, b, c, p, p1, s;

    a = sqrt((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1));
    b = sqrt((x3 - x2) * (x3 - x2) + (y3 - y2) * (y3 - y2));
    c = sqrt((x1 - x3) * (x1 - x3) + (y1 - y3) * (y1 - y3));

    if (a > 0 || b > 0 || c > 0) {
            p = a + b + c;
            p1 = p / 2;
            s = sqrt(p1 * (p1 - a) * (p1 - b) * (p1 - c));
            printf("Perimetr triangle: %.2f\nS triangle: %.2f\n", p, s);
    } 
    else 
    {
    printf("Error\n");
    }
}
