#include<stdio.h>

printNumber(int n){
	if(n>0)
	{
		printf("%d", n);
		printNumber(n-1);
	}
}

int fibo(int n)
{
	int res;
	if(n==0){
		return 0;
	}else if(n==1){
		return 1;
	}else{
		return fibo(n-1)+fibo(n-2);
	}
}

int main()
{
	int n;
	scanf("%d", &n);
	printNumber(n);
	printf("\n");
	printf("%d", fibo(n));
	
	return 0;
}
