#include<stdio.h>
int main()
{
	char one[2];
	char two[2];
	char three[2];
	
	scanf("%c%c%c", &one[0], &one[1], &one[2]);
	getchar();
	scanf("%c%c%c", &two[0], &two[1], &two[2]);
	getchar();
	scanf("%c%c%c", &three[0], &three[1], &three[2]);
	getchar();
	
	printf("%c\n", one[1]);
	printf("%c\n", two[1]);
	printf("%c\n", three[1]);
	
	return 0;
}
