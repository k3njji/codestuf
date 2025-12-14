#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	for(int a=1; a<=y; a++){
	
	int x;
	scanf("%d", &x);
	
	int mat1[x][x], mat2[x][x], mat3[x][x], sum[100][100]={0};
	
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			scanf("%d", &mat1[i][j]);
		}
	}
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			scanf("%d", &mat2[i][j]);
		}
	}
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			scanf("%d", &mat3[i][j]);
		}
	}
	
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			for(int k=0; k<x; k++){
				sum[i][j]+=mat1[i][k]*mat2[k][j];
			}
		}
	}
	int result[100][100]={0};
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			for(int k=0; k<x; k++){
				result[i][j]+=sum[i][k]*mat3[k][j];
			}
		}
	}
	printf("Case #%d:\n", a);
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			printf("%d", result[i][j]);
			if(j!=x-1){
				printf(" ");
			}
		}
		printf("\n");
	}
}
	
	return 0;
}
