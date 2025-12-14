#include<stdio.h>

int main()
{
	
	int x;
	int a, b, c;
	int sum2 = 0;
	int arr[100];
	scanf("%d", &x);
	scanf("%d %d %d", &a, &b, &c);
	int sum1 = a+b+c;
	for(int j=0; j<x; j++){
		scanf("%d", &arr[j]);
		sum2+=arr[j];
		}
	
	int average = (sum1+sum2)/(3+x);
	
	if(average<=a){
		printf("Jojo lolos\n");
	}else{
		printf("Jojo tidak lolos\n");
	}
	
	if(average<=b){
		printf("Lili lolos\n");
	}else{
		printf("Lili tidak lolos\n");
	}
	
	if(average<=c){
		printf("Bibi lolos\n");
	}else{
		printf("Bibi tidak lolos\n");
	}
	
	
	return 0;
}
