#include<stdio.h>

int main()
{
	int x, i;
	scanf("%d", &x);
	int day[x];
	
	for(i=1; i<=x; i++){
		scanf("%d", &day[i]);
	}
	
	int y;
	scanf("%d", &y);
	for(int j=1; j<=y; j++){
		int a, b;
		scanf("%d %d", &a, &b);
		int total=0;
		
		for(int k=a; k<=b; k++){
				total+=day[k];
			}
			printf("Case #%d: %d\n",j ,total);
		}	
	
	return 0;
}
