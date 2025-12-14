#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	for(int j=0; j<y; j++){
	
	int x, i;
	scanf("%d", &x);
	int arr[x];
	
	for(i=0; i<x; i++){
		scanf("%d", &arr[i]);
	}
	
	printf("Case #%d:", j+1);
	
	for(i=x-1; i>=0; i--){
		printf(" %d", arr[i]);
	}
	printf("\n");
}
	return 0;
}
