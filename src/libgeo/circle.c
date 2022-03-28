#include "circle.h"
#include <math.h>
#include <stdio.h>

void circle(double r)
{
    float p, s;
    if (r > 0) {
        p = M_PI * r * 2;
        s = M_PI * r * r;
        printf("Perimetr circle: %.2f\nS circle: %.2f \n", s, p);
    } else {
        printf("Error\n");
    }
}
