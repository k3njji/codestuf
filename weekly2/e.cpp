#include<stdio.h>
int main()
{
	int t;
	scanf("%d\n", &t);
	
	double a;
	scanf("%lf", &a);
	double rea = 4*a/5 ;
	double fah = 9*a/5+32 ;
	double kel = a+273 ;
	printf("%.2lf %.2lf %.2lf\n", rea, fah, kel);
	getchar();
	
	scanf("%lf", &a);
	double rea1 = 4*a/5 ;
	double fah1 = 9*a/5+32 ;
	double kel1 = a+273 ;
	printf("%.2lf %.2lf %.2lf\n", rea1, fah1, kel1);
	getchar();
	
	scanf("%lf", &a);
	double rea2 = 4*a/5 ;
	double fah2 = 9*a/5+32 ;
	double kel2 = a+273 ;
	printf("%.2lf %.2lf %.2lf\n", rea2, fah2, kel2);
	getchar();
	
	return 0;
	
}
