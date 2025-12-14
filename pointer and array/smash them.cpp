#include<stdio.h>

int main()
{
	int o;
	scanf("%d", &o);
	for(int i=1; i<=o; i++){
		
	
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int sum= x*y/100;
	printf("Case #%d: ", i);
	if(sum>z){
		printf("%d\n", z);
	}else if(sum<=z){
		printf("%d\n", sum);
	}
}
	
	
	
	return 0;
}
