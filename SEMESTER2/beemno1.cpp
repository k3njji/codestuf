#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	(x%2 == 0) ? printf("%d is even number", x) : printf("%d is odd number");	
	
	return 0;
}
