#include<stdio.h>

void swap(int x, int y){
	int temp = *x;
	*x = *y;
	*y = temp;
}

int main()
{
	int x = 10;
	int y = 5;
	
	swap(x, y);
	
	printf("%d %d\n", x, y);
	
	return 0;
}
