#include<stdio.h>

int main()
{
	int x, y;
	int sum1;
	scanf("%d %d", &x, &y);
	sum1 = x+y;
	
	for(x; x<=sum1; x++)
	{
		printf("%d\n", x);
	}
	return 0;
}
