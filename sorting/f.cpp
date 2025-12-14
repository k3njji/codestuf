#include<stdio.h>

struct lili{
	char subject[11];
	long long jam;
};

int main()
{
	int x;
	scanf("%d", &x);
	struct lili input[100];
	for(int i=0; i<x; i++){
		scanf("%s %d", &input[i].subject, &input[i].jam);
	}
	
	for(int i=0; i<x; i++){
		printf("%s %d", input[i].subject, input[i].jam);
	}
	
	
	return 0;
}
