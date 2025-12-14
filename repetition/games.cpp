#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
		int x;
	char blt[100];
	for(int z=0; z<y; z++){
	scanf("%d", &x);
	blt[x];
	scanf("%s", &blt);
	int l=0;
	int b=0;
	
	for(int i=0; i<x; i++){
		if(blt[i]=='B'){
			b++;
		}else if(blt[i]=='L'){
			l++;
		}else if(blt[i]=='T'){
			b++;
			l++;
		}
	}
	if(l>b){
		printf("Lili\n");
	}else if(b>l){
		printf("Bibi\n");
	}else if(b==l){
		printf("None\n");
	}
}
	
	return 0;
}
