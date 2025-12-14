#include<stdio.h>

int main()
{
	
	int solve=0;
	int b;
	scanf("%d", &b);
	for(int a=0; a<b; a++){
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	
	if(y>z){
		solve++;
	}
}
	
	printf("%d\n", solve);
	
	return 0;
}
