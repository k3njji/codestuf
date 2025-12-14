#include<stdio.h>

int main()
{
	FILE *fptr;

	fptr = fopen("testdata.in", "r");
	
	int a, b;
	fscanf(fptr, "%d %d", &a, &b);
	printf("%d\n", a+b);
	
	fclose(fptr);
	return 0;
}
