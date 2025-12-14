#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);

	for(int d=1; d<=y; d++){
	
	int x;
	scanf("%d", &x);
	getchar();
	char ans[x];
	char ansk[x];
	
	for(int i=0; i<x; i++){
		scanf("%c", &ans[i]);
	}
	getchar();
	for(int i=0; i<x; i++){
		scanf("%c", &ansk[i]);
	}
	getchar();
	
	int correct = 0;
	for(int i=0; i<x; i++){
		if(ans[i]==ansk[i]){
			correct++;
		}
	}
	
	int sum = correct*100/x;
	printf("Case #%d: %d\n", d, sum);
}
	
	
	return 0;
}
