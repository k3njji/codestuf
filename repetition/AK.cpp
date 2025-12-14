#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	int number[x];
	for(int i=0; i<x; i++){
		scanf("%d", &number[i]);
	}
	for(int i=1; i<x; i++){
		if(number[i]==1){
			printf("%d ", number[i-1]);
		}
	}
	printf("%d\n", number[x-1]);
	
	
	
	return 0;
}
