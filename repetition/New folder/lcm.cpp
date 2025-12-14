#include<stdio.h>

int main()
{
	
	int x, y, total;
	scanf("%d %d", &x, &y);
	
	total = (x>y) ? x:y;

	while(1){
		if((total%x==0) && (total%y==0)){
			break;
		}
		total++;
	}
	printf("%d\n", total);
	
	return 0;
}
