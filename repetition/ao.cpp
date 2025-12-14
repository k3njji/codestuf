#include<stdio.h>

int main()
{
	
	int x, y;
	scanf("%d", &x);
	char arr[100];
	
	for(int i=0; i<x; i++){
		scanf("%d", &y);
		getchar();
		scanf("%[^\n]s", arr);
		getchar();
		printf("Case #%d: ", i+1);
		for (int k=0; k<y; k++){
			if('a'<=arr[k] && arr[k]<='z')
			printf("%c", arr[k]);
		}
		printf("\n");
	}
	
	return 0;
}
