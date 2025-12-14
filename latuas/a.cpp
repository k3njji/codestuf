#include<stdio.h>
int count=0;

int lili(int x){
	if(x==3 || x==4){
		count++;
	}
	if(x==0){
		return 1;
	}else if(x==1){
		return 2;
	}else if(x%3==0){
		return lili(x-x/3)+1;
	}else{
		return lili(x-1)+x+lili(x-2)+1;
	}
}

int main()
{
	int y;
	scanf("%d", &y);
	
	for(int i=1; i<=y; i++){
	int x;
	scanf("%d", &x);
	
	int result = lili(x);
	printf("Case #%d: %d %d\n", i, result, count);
	count=0;
}
	return 0;
}
