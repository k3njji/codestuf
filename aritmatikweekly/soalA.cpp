#include<stdio.h>

int main()
{
	double x;
	double y;
	int t = 3;
	scanf("%d", &t);
	int i;
	double degr[3];
	
	for(i=0; i<3; i++){
		scanf("%lf %lf", &x, &y);
		degr[i] = x*y/360;

	}
	
	for(i=0; i<3; i++){
	printf("%.2lf\n", degr[i]);
	}	
	
	return 0;
}
