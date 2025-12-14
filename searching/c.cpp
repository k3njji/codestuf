#include<stdio.h>

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int numb[x];
	int remv[y];
	for(int i=0; i<x; i++){
		scanf("%d", &numb[i]);
	}
	
	for(int i=0; i<y; i++){
		scanf("%d", &remv[i]);
	}
	
	for(int i=0; i<y; i++){
		for(int j=0; j<x; j++){
			if(numb[j]==remv[i]){
				numb[j]=-1;
			}
		}
	}
	
	int result=-1;
	for(int i=0; i<x; i++){
		if(result<numb[i]){
			result=numb[i];
		}
	}
	
	printf("Maximum number is %d\n", result);
	
//10 2
//5 3 4 2 5 3 5 1 2 2
//4 5
	
	
	
	
	return 0;
}
