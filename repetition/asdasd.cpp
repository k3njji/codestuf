#include<stdio.h>

int main()
{
	int k, i;
	scanf("%d", &k);
	
	for(i=0; i<k; i++){
	int x, y, z, a;
	scanf("%d %d", &x, &y);
	int total=x;
	
	while(x>=y){
		z=x/y;
		a=x%y;
		total+=z;
		x=z+a;

	}
	printf("Case #%d: %d\n", i+1, total);
}
	return 0;
}
