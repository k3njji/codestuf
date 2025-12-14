#include<stdio.h>
int main()
{
	
	int x, y, i;
	char output[100];
	scanf("%d", &x);
	for(i=0; i<x; i++){
		scanf("%d", &y);
		getchar();
		scanf("%[^\n]s", output);
		getchar();
		printf("Case #%d: ", i+1);

		for(int k=0; k<y; k++){
			if('a'<=output[k] && output[k]<='z'){
			printf("%c", output[k]);
			}
	
		}
		printf("\n");
	}
	
	return 0;
}
