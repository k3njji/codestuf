#include<stdio.h>

int main ()
{
	double x, y, z;
		scanf("%lf %lf %lf", &x, &y, &z);
		printf("%.2lf\n", x*20/100 + y*30/100 + z*50/100);
	return 0;
}
