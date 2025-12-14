#include<stdio.h>

int main()
{
	
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	
	int sum=y*z;
	
	if(sum%x!=0){
		printf("NO\n");
	}else{
		printf("YES %d\n", y*z/x);
	}
	
	return 0;
}
