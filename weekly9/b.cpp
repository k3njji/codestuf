#include<stdio.h>

unsigned long long count=0;

unsigned long long fact(unsigned long long x, unsigned long long y){
	if(y>=x){
		y/=x;
		count++;
		return fact(x, y);
	}
	return count;
}

int main()
{
	int a;
	scanf("%d", &a);
	for(int b=1; b<=a; b++){
	unsigned long long x, y;
	scanf ("%llu %llu", &x, &y);
	unsigned long long total;
	total=fact(x, y);
	
	printf("Case #%d: %llu\n", b, total);
	count=0;
}
	return 0;
}
