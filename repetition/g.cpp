#include<stdio.h>

int main()
{
	int x, y=0, i;
	scanf("%d", &x);
	int arr[100000];
	
	for(i=0; i<x; i++){
		scanf("%d", &arr[i]);
		y=y+arr[i];
	}
	printf("%d\n", y);
	
	return 0;
}
