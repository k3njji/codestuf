#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	
	for(int a=1; a<=y; a++){
	
	int x;
	scanf("%d", &x);
	char first[x-1];
	char second[x-1];
	
	scanf("%s", &first);
	
	scanf("%s", &second);
	
	int add=0;
	
	for(int i=0; i<x-1; i++){
		if(first[i]==second[i]){
			add++;
		}
	}
	
	int sum = add*100/x;
	
	printf("Case #%d: %d\n", a, sum);
}

	return 0;
}
