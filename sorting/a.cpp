#include<stdio.h>

int main()
{
	int a;
	scanf("%d", &a);
	for(int b=1; b<=a; b++){
	
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int count=z-1;
	for(int i=z; i<y+z; ++i){
		count++;
		if(count%(x+1)==0){
			count=1;
		}
	}
	printf("Case #%d: %d\n", b, count);
}
	
	return 0;
}
