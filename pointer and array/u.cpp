#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	
	for(int z=1; z<=y; z++){
	int x;
	scanf("%d", &x);
	int number[x];
	int a, b;
	for(int i=1; i<=x; i++){
		scanf("%d", &number[i]);
	}
	scanf("%d %d", &a, &b);
	
	printf("Case #%d : ", z);
	
	if(number[a]==number[b]){
		printf("Draw\n");
	}else if(number[a]>number[b]){
		printf("Bibi\n");
	}else{
		printf("Lili\n");
	}
}
	
	return 0;
}
