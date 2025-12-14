#include<stdio.h>

long long fibo(int z, long long x, long long y){
	if(z==0){
		return x;
	}else if(z==1){
		return y;
	}else{
		return fibo(z-1, x, y)-fibo(z-2, x, y);
	}
}

int main()
{
	int b;
	scanf("%d", &b);
	for(int a=1; a<=b; a++){
	int z;
	long long x, y;
	scanf("%d %lld %lld", &z, &x, &y);
	
	long long result=fibo(z, x, y);
	printf("Case #%d: %lld\n", a, result);
}
return 0;
}
