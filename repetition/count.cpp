#include <stdio.h>

int main()
{
	int a, b;
	scanf("%d", &a);
	
	for(b=0; b<a; b++){
		
	long long x;
	scanf("%lld", &x);
	int y=0;
	
	do{
		y++;
		x/=10;
	}while(x!=0);
	
	printf("Case #%d: %d\n",b+1, y);
}
	
	
	return 0;
}

 

