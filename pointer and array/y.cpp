#include<stdio.h>
#include<string.h>

int main()
{
	
	int x;
	int len;
	scanf("%d", &x);
	char number[1000];
	scanf("%s", &number);
	len=strlen(number);
	
	int a;
	char b;
	
	for(int i=0; i<x; i++){
		scanf("%d %c", &a, &b);
		number[a-1] = {b};
	}
	
	for(int i=0; i<len; i++){
		printf("%c", number[i]);
	}
	
	
	
	
	return 0;
}
