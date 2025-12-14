#include<stdio.h>

int main()
{
	int z;
	scanf("%d", &z);
	for(int p=1; p<=z; p++){
	int y=97;
	int x;
	scanf("%d", &x);
	printf("Case #%d: ", p);
	for(int i=0; i<x; i++){
		printf("%c", y++);
	}
	printf("\n");
}
	
	
	
	return 0;
}
