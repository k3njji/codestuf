#include <stdio.h>
int main()
{
	double x, y, z;
	scanf("%lf %lf %lf", &x, &y, &z);
	double sum = (x+x+x)*y+y*z;
	printf("%.3lf\n", sum);
	
	return 0;
	
}
