#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	for(int b=1; b<=y; b++){
	
	int x;
	scanf("%d", &x);
	int matrix[x][x];
	
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			scanf("%d", &matrix[i][j]);
		}
	}
	int total[x]={0};
	
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			total[j]+=matrix[i][j];
		}
	}
	printf("Case #%d:", b);
	for(int k=0; k<x; k++){
	printf(" %d", total[k]);
}
printf("\n");
}
	return 0;
}
