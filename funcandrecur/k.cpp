#include<stdio.h>

int fibo(int z, int x, int y){
	if(z==0){
		return x;
	}else if(z==1){
		return y;
	}else{
		return fibo(z-1, x, y)+fibo(z-2, x, y);
	}
}

int main()
{
	int z;
	int x, y;
	scanf("%d %d %d", &x, &y, &z);
	
	int result=fibo(z, x, y);
	printf("%d\n", result);
return 0;
}
