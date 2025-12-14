#include<stdio.h>
int main()
{
	int x, y, k;
	scanf("%d %d %d", &x, &y, &k);
	int sum = (y+x)/2;
	int sum2 = (y-x)/2;
	if(sum==k && y>=k && k>=x && y>=x){	
		printf("%d\n", sum2);
	} else {
		printf("-1\n");
	}
	
	return 0;
}
