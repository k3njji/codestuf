#include<stdio.h>


int function(int x, int count){
	int result;
	if(x==0){
		return 1;
	}else if(x==1){
		return 2;
	}else if(x%5==0){
		if(x%3==0){
			count++;
		}
		x=x*2;
		return x;
	}else{
		if(x%3==0){
			count++;
		}
		result=function(x-1, count)+x+function(x-2, count)+x-2;
		return result; 
	}
}

int main()
{
	int y;
	scanf("%d", &y);
	for(int i=1; i<=y; i++){
	int x;
	scanf("%d", &x);
	int count=0;
	int result=function(x, count);

	printf("Case #%d: %d %d\n", i, result, count);
	count=0;
}
	
	return 0;
}
