#include<stdio.h>
int main()
{
	long a, b, c, d;
	long i;
	long e[4];
	
	for(i=0; i<3; i++){
		scanf("(%ld+%ld)x(%ld-%ld)", &a, &b, &c, &d);
		e[i] = (a+b)*(c-d);
		getchar();
	}
	
	
	for(i=0; i<3; i++){
		printf("%ld\n", e[i]);
	}
	
	return 0;
}
