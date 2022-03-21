#include "libgeo/circle.h"
#include "libgeo/triangle.h"
#include <math.h>
#include <stdio.h>

int main()
{
    int a;
    while (1) {
        printf("1. Cirle\n2. Triangle\n3. Poligon\nChoose your figure: ");
        scanf(" %d", &a);
        if (a == 1) {
            circle();
            break;
        }
        if (a == 2) {
            triangle();
            break;
        }
        else {
            printf("Error\n");
            return 0;
        }
    }
    return 0;
}
