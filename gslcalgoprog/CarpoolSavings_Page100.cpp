#include<stdio.h>
int main()
{
	printf("Car-Pool Savings Calculator\n");
	puts("Carpool can save you up to 50%% of your transportaon cost\n");
	
	double md, cpg, mpg, pf, t;
	/*
	md = miles driven
	cpg = cost per galloon
	mpg = miles per galloon
	pf = parking fees
	t = tolls
	*/
	printf("Total miles driven per day\t: ");
	scanf("%lf", &md);
	printf("Cost per gallons of gasoline\t: ");
	scanf("%lf", &cpg);
	printf("Average miles per gallon\t: ");
	scanf("%lf", &mpg);
	printf("Parking fees per day\t\t: ");
	scanf("%lf", &pf);
	printf("Tolls per day\t\t\t: ");
	scanf("%lf", &t);
	
	printf("\n");
	
	double exp = md/mpg*cpg+pf+t;
	printf("Your daily Driving cost : $%.lf\n", exp);
	printf("With Carpool you can save up to $%.lf\n", exp*50/100);
	
	
	return 0;
	
}











