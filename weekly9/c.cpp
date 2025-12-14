#include<stdio.h>

unsigned long long count=0;

unsigned long long fact(unsigned long long x, unsigned long long y, unsigned long long total){
	if(total<=y){
		total*=x;
		count++;
		fact(x, y, total);
	}
	return total;
}

int main()
{
	int a;
	scanf("%d", &a);
	for(int b=1; b<=a; b++){
	unsigned long long x, y;
	scanf ("%llu %llu", &x, &y);
	unsigned long long total=x;
	total=fact(x, y, total);
	
	printf("Case #%d: ", b);
	if(total>y){
		printf("%llu\n", count-1);
	}else{
		printf("%llu\n", count);
	}
	count=0;
}
	return 0;
}
