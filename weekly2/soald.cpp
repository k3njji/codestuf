#include<stdio.h>
int main()
{
	double x;
	scanf("%lf", &x);
	double sum = x/2*(2*100+(x-1)*50);
	printf("%.lf\n", sum);
	
	return 0;
}
