#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	int y = 1;
	
	for(int i=0; i<x; i++){
		y*=2;
		y+=1;
	}
	
	printf("%d\n", y);
	
	return 0;
}
