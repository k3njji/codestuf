#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	for(int i=0; i<y; i++){
		
	int x, row, space, symbol;
	scanf("%d", &x);
	
	for(row=1; row<=x; row++){
		for(space=1; space<=(x-row); space++){
			printf(" ");
		}for(symbol=1; symbol<=((2*row)-1); symbol++){
			printf("*");
		}
		printf("\n");
	}
}
	
	return 0;
}
