#include<stdio.h>
int main()
{
	int a, b, c, d;
	
	for(int i=0; i<4; i++){
		scanf("(%d+%d)x(%d-%d)", &a, &b, &c, &d);
		printf("%d\n", (a+b)*(c-d));
		getchar();
	}
	
	return 0;
}
