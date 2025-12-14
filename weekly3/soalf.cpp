#include<stdio.h>
int main()
{
	
	int x, y=0, i;
	int arr[2000];
	
	scanf("%d", &x);
	
	for(i=0; i<x; i++){
		scanf("%d", &arr[i]);
		y = y + arr[i];
		
		if(y==9){
			y = 21;
		}else if(y==33){
			y = 42;
		}else if(y==76){
			y = 92;
		}else if(y==53){
			y = 37;
		}else if(y==80){
			y = 59;
		}else if(y==97){
			y = 88;
		}else{
			y;
		}
	}
	
	printf("%d\n", y);
	
	return 0;
}
