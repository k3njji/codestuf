#include<stdio.h>

unsigned long long fact(unsigned long long a){
	if(a==0){
		return 0%1000000007;
	}else if(a==1){
		return 1%1000000007;
	}else{
		return (a*fact(a-1)%1000000007);
	}
}

int main()
{
	int t;
	scanf("%d", &t);
	for(int j=1; j<=t; j++){
		
	unsigned long long x, a;
	unsigned long long total = 1;
	scanf("%llu", &x);
	for(int i=0; i<x; i++){
		scanf("%llu", &a);
		total=total*fact(a)%1000000007;
	}
	printf("Case #%d: %llu\n", j, total);
}
	return 0;
}
