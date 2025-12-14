#include<stdio.h>

long long one(long long x){
	int result=0;
	if(x==1){
		return 1;
	}else if(x%2==0){
		result=one(x/2);
	}else if(x%2==1){
		result=one(x-1)+one(x+1);
	}
	return result;
}

int main()
{
	int y;
	scanf("%d", &y);
	for(int j=1; j<=y; j++){
	long long x;
	scanf("%lld", &x);
	long long result=one(x);
	printf("Case #%d: %d\n", j, result);
}
return 0;
}
