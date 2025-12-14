#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	getchar();
	int number[100][100];
	
	for(int i=1; i<=x; i++){
		for(int z=1; z<=x; z++){
			scanf("%d", &number[i][z]);
			getchar();
		}
	}
	int kosong=0;
	
	for(int i=1; i<=x; i++){
		for(int z=1; z<=x; z++){
			if(number[i][z]==0 || number[i][z]!=x){
				kosong++;
				break;
			}
			
		}
	}
	printf("%d\n", kosong);
	
	return 0;
}
