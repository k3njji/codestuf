#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	for(int a=1; a<=y; a++){

	long long x;
	scanf("%lld", &x);
	
	long long numb[x][x];
	for(int i=0; i<x; i++){
		for(int j=0; j<x; j++){
			scanf("%lld", &numb[i][j]);
		}
	}
	
	printf("Case #%d:", a);
	
	for(int i=0; i<x; i++){
		long long temp=0;
		for(int j=0; j<x; j++){
			temp=temp+numb[j][i];
		}
		printf(" %lld", temp);
	}
	printf("\n");
}
	
	
	return 0;
}
