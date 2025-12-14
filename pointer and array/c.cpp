#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	int number[100];
	
	for(int i=1; i<=x; i++){
		scanf("%d", &number[i]);
	}
	
	int y;
	scanf("%d", &y);
	
	int a, b;
	
	for(int i=1; i<=y; i++){
		scanf("%d %d", &a, &b);
		number[a] = {b};
		printf("Case #%d:", i);
		
		for(int k=1; k<=x; k++){
			printf(" %d", number[k]);
		}
		printf("\n");
	}
	
	return 0;
}

