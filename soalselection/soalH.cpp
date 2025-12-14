#include<stdio.h>
int main()
{
	
	char a, b, c;
	scanf("%c %c %c", &a, &b, &c);

	if(a<b && b<c){
		printf("1 2 3\n");
	}else if(a>b && b>c){
		printf("3 2 1\n");
	}else if(a>b && b<c && a<c){
		printf("2 1 3\n");
	}else if(a>b && b<c && a>c){
		printf("2 3 1\n");
	}else if(a<b && b>c && a<c){
		printf("1 3 2\n");
	}else{
		printf("3 1 2\n");
	}
	
	return 0;
}
