#include<stdio.h>

int fibo(int n)
{
	if(n==0){
		return 0;
	}else if(n%2==1){
		return 1;
	}else{
		return fibo(n-1)+fibo(n-2);
	}
}

int main()
{
	int x;
	scanf("%d", &x);
	
	int result=fibo(x);
	printf("%d\n", result);
	return 0;
}
