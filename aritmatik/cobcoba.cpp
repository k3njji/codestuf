#include <stdio.h>
int main()
{
	float x, y, z;
	scanf("%f %f %f", &x, &y, &z);
	float sum = x*3*y+x*z;
	printf("%.2f", sum);
	
	return 0;
}
