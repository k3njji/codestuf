#include<stdio.h>

int main()
{
	
	int y;
	scanf("%d", &y);
	
for(int d=1; d<=y; d++){
	
	long long x, b;
	scanf("%lld %d", &x, &b);
	
	

	long long mod[10000];
	long long i=0;
	
	while(x!=0){
		mod[i++]=x%2;
		x/=2;
	}

	printf("%d\n", mod[b]);
}

	
	return 0;
}
