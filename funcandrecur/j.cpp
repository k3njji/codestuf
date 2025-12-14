#include<stdio.h>

long long game(long long count, long long x){
	count++;
	while(x>1){
		if(x%2==1){
			x=x*3+1;
			return game(count, x);
		}else{
			x=x/2;
			return game(count, x);
		}
	}
	return count;
}

int main()
{
	int y;
	scanf("%d", &y);
	for(int i=1; i<=y; i++){
	
	long long x;
	scanf("%lld", &x);
	long long count=0;
	long long result=game(count, x);
	
	int total=result-1;
	
	printf("Case #%d: ", i);
	if(total%2==1){
		printf("Jojo\n");
	}else{
		printf("Lili\n");
	}
}
	return 0;
}
