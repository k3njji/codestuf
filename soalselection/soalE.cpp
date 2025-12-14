#include<stdio.h>

int main()
{
	float a, b, c, d;
	scanf("%f %f %f %f", &a, &b, &c, &d);
	if((a*b)>(c+d)){
		printf("True\n");
	} else {
		printf("False\n");
	}
	
	return 0;
}
