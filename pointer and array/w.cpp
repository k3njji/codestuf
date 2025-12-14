#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	for(int a=1; a<=y; a++){
	int x;
	scanf("%d", &x);
	
	int num[x+1];
	
	for(int i=1; i<=x; i++){
		scanf("%d", &num[i]);
	}
	
	int result[x+1]={0};
	
	for(int i=1; i<=x; i++){
		for(int j=1; j<=x; j++){
			for(int k=1; k<=x; k++){
				if(num[i]==num[j]+num[k]){
					result[i]++;
				}
			}
		}
	}
	int count=0;
	for(int i=1; i<=x; i++){
		if(result[i]>1){
			count++;
		}
	}
	printf("Case #%d: %d\n", a, count);
}
	return 0;
}
