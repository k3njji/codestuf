#include<stdio.h>
int func(int x){
	if(x==0){
		return 0;
	}else if(x==1){
		return 1;
	}else{
		return func(x-1)+func(x-2);
	}
}


int main()
{
	int x;
	scanf("%d", &x);
	
	int result=func(x);
	printf("%d", result);
	
	return 0;
}
