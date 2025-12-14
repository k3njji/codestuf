#include<stdio.h>

int main(){
	
	int x;
	scanf("%d", &x);
	int tmpx=1;
	for(int i=2; i<x; i++){
		if(x%i==0){
			tmpx=0;
			break;
		}
	}
	if(tmpx==1){
		printf("prime");
	}else{
		printf("nonprime");
	}
	
	return 0;
}
