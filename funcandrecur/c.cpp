#include<stdio.h>

int acker(int x, int y){
	if(x==0){
		return y+1;
	}else if(x>0 && y==0){
		acker(x-1, 1);
	}else if(x>0&&y>0){
		acker(x-1, acker(x, y-1));
	}
}

int main()
{
	int x, y;
	scanf("%d %d", &x, &y);
	int result=acker(x, y);
	
	printf("result: %d\n", result);
	return 0;
}
