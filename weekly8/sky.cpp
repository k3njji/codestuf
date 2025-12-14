#include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	getchar();
	char sym[x][x];
	
	for(int i=0; i<x; i++){
			scanf("%s", &sym[i]);
			getchar();
		}
		
	for(int i=x-1; i>=0; i--){
		for(int j=x-1; j>=0; j--){
			printf("%c", sym[i][j]);
		}
		printf("\n");
	}
	
	return 0;
}
