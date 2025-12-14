#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	int arr[x][x];
	int sum=x*x*2;
	
	for(int i=0; i<x; i++){
		for(int k=0; k<x; k++){
			scanf("%d", &arr[i][k]);
		}
	}
	int a = 0;
	for(int i=0; i<x; i++){
		for(int k=0; k<x; k++){
			for(int l=0; l<x; l++){
				if(arr[i][k]==arr[i][l]){
					a++;
				}
			}
		}
	}
	
	for(int i=0; i<x; i++){
		for(int k=0; k<x; k++){
			for(int l=0; l<x; l++){
				if(arr[k][i]==arr[l][i]){
					a++;
				}
			}
		}
	}
	if(a==sum){
		printf("Yay\n");
	}else{
		printf("Nay\n");
	}
	
	
	
	
	return 0;
}
