#include<stdio.h>

int main()
{

int t = 3;
scanf("%d", &t);

double p, n, p1, n1, p2, n2;
scanf("%lf %lf", &p, &n);
getchar();
scanf("%lf %lf", &p1, &n1);
getchar();
scanf("%lf %lf", &p2, &n2);
getchar();

double sum = p/100*n;
double sum1 = p1/100*n1;
double sum2 = p2/100*n2;

printf("%lf\n", sum);
printf("%lf\n", sum1);
printf("%lf\n", sum2);

return 0;

}
