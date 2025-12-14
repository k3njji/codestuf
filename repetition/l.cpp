#include<stdio.h>

int main()
{
	
	int k, i;
	scanf("%d", &k);
	
	for(i=0; i<k; i++){
		int x, y;
		scanf("%d %d", &x, &y);
		int sum1, sum2;
		int lol=x;
		while(x>=y){
			sum1 = x/y;
			sum2 = x%y;
			lol+=sum1;
			x=sum1+sum2;
		}
		printf("Case #%d: %d\n", i+1, lol);
	}
	
	return 0;
}
