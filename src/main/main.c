#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
//#include "hfunclib/thevvod.h"
//#include "hfunclib/calccircle.h"
//#include "hfunclib/calctriangle.h"
#include "libmake/functions.h"

#define pi 3.14

int main()
{
	int j, i = 0;
	float pointx[5][5], pointy[5][5], number1[5];
	char ans[2], yes[2] = "y";
	for (j = 0; j < 5; j++)
	{
		printf("\nWould you like to add object?(y/n)>");
		scanf("%s", &ans[0]);
		if (strcmp(ans, yes) == 0)
		{
			thevvod(pointx, pointy, number1, i);

			i++;
		}
		else
			break;
	}
}
