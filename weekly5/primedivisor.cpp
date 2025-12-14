#include<stdio.h>

int main()
{

	int x;
	scanf("%d", &x);
	int y = 2;
	
	for(y=2; x>1; y++){
		int total = 0;
		while(x%y==0)
		{
			printf("%d ", y);
			x = x/y;
			total+=y;
		}
	}

	return 0;	
}

