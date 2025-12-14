#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	
	for(int a=1; a<=y; a++){
	int x;
	scanf("%d", &x);
	getchar();
	char ans[x];
	char anskey[x];
	for (int b=0; b<x; b++){
		scanf("%c", &ans[b]);
	}
	for (int k=0; k<x; k++){
		scanf("%c", &anskey[k]);
	}
	
	int correct = 0;
	
	for(int i=0; i<x; i++){
		if(ans[i]==anskey[i]){
			correct++;
		}
	}
	
	int sum = (correct/x)*100;
	
	printf("Case #%d: %d\n", a, sum);
}
	return 0;
}
