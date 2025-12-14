#include<stdio.h>
int main()
{
	
	int x, y=0, i;
	scanf("%d", &x);
	int arr[2000];
	for(i=0; i<x; i++){
		scanf("%d", &arr[i]);
			y = y + arr[i];
	if(y==12){
		y = 28;
	}else if(y==35){
		y = 7;
	}else if(y==30){
		y = 10;
	}else if(y>=40){
		y = y-40;
	}else{
		y;
	}	
	}

	printf("%d\n", y);
	

	return 0;
}
