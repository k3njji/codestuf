#include<stdio.h>

int main()
{
	long long int x;
	scanf("%lld", &x);
	for(long long int a=1; a<=x; a++){
		long long int y;
		scanf("%lld", &y);
		long long int numb[y];
		long long int total=0;
		for(long long int i = 1; i<=y; i++){
			if(y%i==0){
				total++;
			}
		}
		printf("Case #%d: %lld\n", a, total);
	}
	
	
	
	return 0;
}
