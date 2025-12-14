#include<stdio.h>
int main()
{
	//input
	printf("Body Mass Index (BMI) Calculator\n");
	double w, h;
	printf("Input Weight (in Kilograms)\t: ");
	scanf("%lf", &w);
	getchar();
	printf("Input Height (in Meters)\t: ");
	scanf("%lf", &h);
	getchar();
	
	double sum = w/(h*h);
	//output
	printf("Your Body Mass Index\t\t: %.1lf\n", sum); 
	
	printf("\n");
	
	puts("BMI VALUES");
	puts("Underweight:\t less than 18.5");
	puts("Normal:\t\t between 18.5 and 24.9");
	puts("Overweight:\t between 25 and 29.9");
	puts("Obese:\t\t 30 or greater\n");
	
	return 0;
	
}
