#include<stdio.h>

int main()
{
	
	int y, o;
	scanf("%d", &y);
	
	for(o=1; o<=y; o++){
	
	int x, i;
	scanf("%d", &x);
	int ar[x];
	int arr[x];
	
	for(i=1; i<=x; i++){
		scanf("%d", &ar[i]);
	}
	for(i=1; i<=x; i++){
		scanf("%d", &arr[i]);
	}
		printf("Case #%d:", o);
	for(i=1; i<=x; i++){
		int total = 0;
		total=ar[i]-arr[i];
		printf(" %d", total);
	}
	printf("\n");
}
	return 0;
}
/*5
3 4 5 1 8
1 3 9 1 5*/ 
