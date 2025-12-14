#include<stdio.h>

int main()
{
	int t;
	scanf("%d", &t);
	for(int i=1; i<=t; i++){
	
	int x, y;
	scanf("%d %d", &x, &y);
	
	double result= 2*3.14*x*(x+y);
	printf("Case #%d: %0.2lf\n", i, result);
}
	
	return 0;	
}
