#include<stdio.h>

int main()
{
	
	int x, y;
	int k = 0;
	scanf("%d %d", &x, &y);
	for(int i=0; i<x; i++){
		int z;
		scanf("%d", &z);
		if(z<y){
			k++;
		}else;
		
		
	}
	printf("%d\n", k);
	
	
	
	
	return 0;
}
