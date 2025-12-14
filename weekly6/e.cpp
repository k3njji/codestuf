#include<stdio.h>

int main()
{
	
	int y;
	scanf("%d", &y);
	
	for(int b=1; b<=y; b++){
	
	int x;
	scanf("%d", &x);
	int arr[x][x];
	
	for (int i=0; i<x; i++){
		for (int j=0; j<x; j++){
			scanf("%d", &arr[i][j]);
		}
	}
	
	int total[x] = {0};
	
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			total[j]+=arr[i][j];
		}
	}
	printf("Case #%d:", b);
	for (int i=0; i<x; i++){
		printf(" %d", total[i]);
	}
	printf("\n");
}
	
	
	return 0;
}
