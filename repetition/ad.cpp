#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	int number[1001]={0};
	for(int i=0; i<x; i++){
		int k;
		scanf("%d", &k);
		number[k]++;
	}
	
	for(int i=0;i<x;i++){
		printf("%d", number[i]);
	}
	int a=0;
	
	for(int i=1; i<=1000; i++){
		if(number[i]>a){
			a=number[i];
		}
	}
	
	printf("%d\n", a);
	return 0;
}
