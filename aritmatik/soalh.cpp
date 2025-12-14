#include<stdio.h>
int main()
{
	int t = 3;
	printf("%d\n", t);
	
	
	float a, b, c, d;
	scanf("%f %f %f %f", &a, &b, &c, &d);
	float sum = 2*a+4*b/2+4*c/3+d/2;
	printf("%0.2f\n", sum);
	getchar();
	
	scanf("%f %f %f %f", &a, &b, &c, &d);
	float sum2= 2*a+4*b/2+4*c/3+d/2;
	printf("%0.2f\n", sum2);
	
	scanf("%f %f %f %f", &a, &b, &c, &d);
	float sum3= 2*a+4*b/2+4*c/3+d/2;
	printf("%0.2f\n", sum3);
	

	return 0;
}
