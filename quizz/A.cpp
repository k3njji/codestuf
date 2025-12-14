#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	for(int i=0; i<x; i++){
		int y;
		scanf("%d", &y);
		int count=0;
		
		if(y>0){
		
		do{
			++count;
			y/=10;
		}while(y!=0);
	}else if(y==0){
		count;
	}

		if(count%2==0 && y%2==0){
			printf("YES\n");
		}else{
			printf("NO\n");
		}
	}
	
	return 0;
}
