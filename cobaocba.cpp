#include<stdio.h>

int main()
{
	
	int x, y, z;
	scanf("%d", &x);
	z=0;
	
	for (int i=0; i<x; i++){
		scanf("%d", &y);
		z+=y;
		printf("%d\n", z);
	}
	
	return 0;
}
