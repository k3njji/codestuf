#include<stdio.h>
int main()
{
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
	double sum = x*y*z;
	printf("%.lf\n", sum);
	
	return 0;
	
}
