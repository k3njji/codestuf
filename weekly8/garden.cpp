#include<stdio.h>

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int gard[x+1][y+1];
	for(int i=1; i<=x; i++){
		for(int j=1; j<=y; j++){
			scanf("%d", &gard[i][j]);
		}
	}
	
	int z, a, b, c;
	scanf("%d", &z);
	
	for(int i=1; i<=z; i++){
		scanf("%d %d %d", &a, &b, &c);
		for(int j=1; j<=x; j++){
			for(int k=1; k<=y; k++){
				if(j==a&&k==b){
					gard[j][k]=c;
				}
			}
		}
	}
	
	for(int i=1; i<=x; i++){
		for(int j=1; j<=y; j++){
				printf("%d", gard[i][j]);
				if(j!=y){
					printf(" ");
				}
		}
		printf("\n");
	}
	
	return 0;
}
