#include<stdio.h>

int function(int x){
	if(x==1){
		return 1;
	}else if(x%2==0){
		return x/2;
	}else if(x%2==1){
		return x*3+1;
	}
}


int main()
{
	int j;
	scanf("%d", &j);
	for(int a=1; a<=j; a++){
	int x, y;
	scanf("%d %d", &x, &y);
	
	int des=0;
	
	if(x==0||y==0){
		des=0;
	}else if(x==y){
		des=1;
	}else{
	while(x!=1){
		x=function(x);
		if(x==y){
			des=1;
		}
	}
}
	
	printf("Case #%d: ", a);
	if(des==0){
		printf("NO");
	}else{
		printf("YES");
	}
	printf("\n");
}
	
	return 0;
}
