#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	for(int a=1; a<=y; a++){
	long long int x;
	scanf("%lld", &x);
	
	long long int binary[64];
	long long int i=0;
	
	while(x!=0){
		binary[i]=x%2;
		x /= 2;
		i++;
	}
	
	printf("Case #%d: ", a);
	for(long long int j = i-1; j>=0; j--){
		printf("%lld", binary[j]);
	}
	printf("\n");
}
	
	return 0;
}
