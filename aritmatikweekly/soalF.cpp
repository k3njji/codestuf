#include<stdio.h>

int main()
{
	double x, y;
	scanf("%lf %lf", &x, &y);
	printf("%.2lf\n", x*((1+y/100)*(1+y/100)*(1+y/100)));
	
	return 0;
}
