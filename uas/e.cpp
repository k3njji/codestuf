#include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	for(int a = 1; a<=x; a++){
		int y;
		scanf("%d", &y);
		int numb [y];
		
		int total=0;
		
		for(int i=0; i<y; i++){
			scanf("%d", &numb[i]);
			total+=numb[i];
		}
		printf("Case #%d: %d\n", a, total);
	}
	
	
	return 0;
}
