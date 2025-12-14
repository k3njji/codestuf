#include<stdio.h>

int main()
{
	
	int x, i, z;
	scanf("%d", &x);
	int number[x][x];
	int add=0;
	
	for(int i=0; i<x; i++){
		for(int z=0; z<x; z++){
			scanf("%d", &number[i][z]);
		}
	}
	for(int i=0; i<x; i++){
		for(int z=1; z<x; z++){
			if(number[i-i][i-i]==number[i-i][z]){
				add++;
			}
		}
	}
	
	printf("%d", add);
//	if(add==0){
//		printf("Yay\n");
//	}else{
//		printf("Nay\n");
//	}
	
	
	return 0;
}
