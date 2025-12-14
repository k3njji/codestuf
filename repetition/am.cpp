#include<stdio.h>

int main()
{
	
	int y;
	scanf("%d", &y);
	
	for(int h=1; h<=y; h++){
	int x;
	scanf("%d", &x);
	printf("Case #%d:\n", h);
	
	for(int i=1; i<=x; i++){
		if((i%3==0 ||i%5==0) && i%15!=0){
			printf("%d Jojo\n", i);
		}else{
			printf("%d Lili\n", i);	
		}
		
	}
}
	return 0;
}
