#include<stdio.h>

int main()
{
	
	int x, k, i, j;
	scanf("%d %d", &x, &k);
	
	for(i=1; i<=x; i++){
		for (j=1; j<=x; j++){
			printf("#");
		}
		printf("\n");
	}
	printf("\n");
	for(i=1; i<=x; i++){
		for(j=1; j<=x; j++){
			if(i%k==0){
				printf("#");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	printf("\n");
	
		for(i=1; i<=x; i++){
		for(j=1; j<=x; j++){
			if(j%k==0){
				printf("#");
			}else{
				printf(".");
			}
		}
		printf("\n");
	}
	
	return 0;
}
