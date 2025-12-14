#include<stdio.h>

void printFibo(int x, char a, char b){
	if(x==0){
		printf("%c", a);
	}else if(x==1){
		printf("%c", b);
	}else{
		printFibo(x-1, a, b), printFibo(x-2, a, b);
	}
}

int main()
{
	int y;
	scanf("%d", &y);
	for(int i=1; i<=y; i++){
		int x;
		char a, b;
		scanf("%d %c %c", &x, &a, &b);
		printf("Case #%d: ", i);
		printFibo(x, a, b);
		printf("\n");
		}
	return 0;
}
