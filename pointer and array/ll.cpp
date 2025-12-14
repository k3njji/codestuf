#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	int arr[x][x];
	int y[x+1]={0};
	for(int i=0; i<x; i++){
		for(int k=0; k<x; k++){
			scanf("%d", &arr[i][k]);
			y[arr[i][k]]++;
		}
	}
	for(int i=0; i<x; i++){
		printf("%d\n", y[i]);
	}
	int a=0;
	for(int i=0; i<=x; i++){
		if(y[i]>x){
			a++;
		}
	}
	
	printf("%d\n", a);
	
	
	
	
	
	return 0;
}
