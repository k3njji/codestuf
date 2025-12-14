#include<stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	for(int b=1; b<=a; b++){
	int x, y;
	scanf("%d %d", &x, &y);
	
	int numb[x];
	for(int i=0; i<x; i++){
		scanf("%d", &numb[i]);
	}
	
	int count=0;
	for(int i=0; i<x; i++){
		if(numb[i]>=y){
			count++;
		}
	}
	
	printf("Case #%d: %d\n", b, count);
}
	
	return 0;
}
