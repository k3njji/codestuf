#include<stdio.h>

int main()
{
int y;
scanf("%d", &y);
int x, i, j;
	scanf("%d", &x);


for(int a=0; a<y; a++){
	
	for(i=1; i<=x; i++){
		for(j=1; j<=x; j++){
			printf(" ");
		}
		for(j=1; j>=i; j++){
		printf("*");
		}
		printf("\n");
	}
}
return 0;
}

