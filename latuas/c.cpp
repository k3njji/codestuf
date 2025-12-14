#include<stdio.h>

int main()
{
	long long int x, y;
	scanf("%lld %lld", &x, &y);
	long long int o=0;
	
	for(int i=x; i<=y; i++){
		o+=i;
	}
	
	printf("%lld\n", o);
	
	return 0;
}
