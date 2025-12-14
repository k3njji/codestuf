#include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	int numb1[x];
	int numb2[x];
	
	for(int i=1; i<=x; i++){
		scanf("%d", &numb1[i]);
	}
	for(int i=1; i<=x; i++){
		scanf("%d", &numb2[numb1[i]]);
	}
	
	printf("%d", numb2[0]);
	
	for(int i=1; i<x; i++){
		printf(" %d", numb2[i]);
	}
	
	printf("\n");
	
	return 0;
}
