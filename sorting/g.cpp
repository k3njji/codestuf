#include<stdio.h>

int main()
{
	int b;
	scanf("%d", &b);
	for(int a=1; a<=b; a++){
	int x, y;
	scanf("%d %d", &x, &y);
	int numb[x];
	
	for(int i=0; i<x; i++){
		scanf("%d", &numb[i]);
	}
	int count=0;
	
	for(int i=0; i<x-1; i++){
		for(int j=0; j<x-i-1; j++){
			if(numb[j]>numb[j+1]){
				count++;
				int temp=numb[j];
				numb[j]=numb[j+1];
				numb[j+1]=temp;
			}
		}
	}
	printf("Case #%d: %d\n", a, count*y);
}
	
	
	return 0;
}
