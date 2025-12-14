#include<stdio.h>

int main()
{
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int arr[100][100]={0};
	
	int a, b, c;
	
	for(int i=0; i<z; i++){
		scanf("%d %d %d", &a, &b, &c);
		for(int j=0; j<x; j++){
			for(int k=0; k<y; k++){
				if(j==a&&k==b){
					arr[j][k]=c;
				}
			}
		}
	}
	
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			printf("%d", arr[i][j]);
			if(j!=y-1){
				printf(" ");
			}
		}
		printf("\n");
	}
	
	
	
	return 0;
}
