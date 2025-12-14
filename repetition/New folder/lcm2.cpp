#include<stdio.h>

int main()
{
	
	int x, y;
	scanf("%d %d", &x, &y);
	int k=x;
	int j=y;
	
	while(1){
		if(x==y){
			break;
		}if(x<y){
			x+=k;
		}else{
			y+=j;
		}
		printf("%d %d", x, y);
	}
	printf("%d", x);
	
	return 0;
}
