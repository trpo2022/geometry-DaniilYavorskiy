#include "../src/libmake/functions.c"
#include "../thirdparty/ctest.h"
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

CTEST(set_geometry, test_squarecircle)
{
    int i = 0;
    const int exp = 314;
    float number1[10];
    float ploshad[5];
    number1[i] = 10;
    squarecircle(ploshad, i, number1);
    ASSERT_EQUAL(exp, ploshad[i]);
}
