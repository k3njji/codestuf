#include<stdio.h>

int main()
{
	long long a;
	scanf("%lld", &a);
	for(long long b=1; b<=a; b++){
		
	long long x;
	scanf("%lld", &x);
	long long temp;
	long long reverse=0;
	long long y=x;
	
	while(x!=0){
		temp=x%10;
		reverse=(reverse*10)+temp;
		x=x/10;
	}

	printf("Case #%lld: %lld\n", b, y+reverse);
}
	
	return 0;
}
