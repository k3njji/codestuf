#include<stdio.h>

int sum(int x, int num[]){
	int total=0;
	for(int i=0; i<x; i++){
		total+=num[i];
	}
	return total;
}

int main()
{
	int y;
	scanf("%d", &y);
	for(int j=1; j<=y; j++){
	int x;
	scanf("%d", &x);
	int num[x];
	
	for(int i=0; i<x; i++){
		scanf("%d", &num[i]);
	}
	
	int result=sum(x, num);
	
	printf("Case #%d: %d\n", j, result);
}
}
