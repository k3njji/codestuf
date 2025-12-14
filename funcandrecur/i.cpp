#include<stdio.h>
int count=0;

int fibo(int x){
	if(x==0){
		count++;
		return 1;
	}else if(x==1){
		count++;
		return 2;
	}else{
		count++;
		return fibo(x-1)+fibo(x-2);
	}
	return 0;
}

int main()
{
	int y;
	scanf("%d", &y);
	for(int j=1; j<=y; j++){
	
	int x;
	scanf("%d", &x);
	int result=fibo(x);
	
	printf("Case #%d: %d\n", j, count);
	count=0;
}
	return 0;
}
