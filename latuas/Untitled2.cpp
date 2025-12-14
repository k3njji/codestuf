#include<stdio.h>

int main()
{
	long long int x;
	scanf("%lld", &x);
	
	long long int binary[x];
	long long int i=0;
	
	while(x!=0){
		binary[i++]=x%2;
		x /= 2;
	}
	
	for(long long int j = i-1; j>0= ; j++){
		printf("%d", binary[j]);
	}
	printf("\n");
	
	return 0;
}
