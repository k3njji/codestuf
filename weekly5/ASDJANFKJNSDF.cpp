#include<stdio.h>

int main()
{
	
	int y;
	scanf("%d", &y);
	
	for(int k=0; k<y; k++){
		int x;
	scanf("%d", &x);
	int sum=0;
	for(int i=2; i<=x; i++){
		if(x%i==0){
			int tmpx=1;
		for(int j=2; j<i; j++){
			if(i%j==0){
				tmpx=0;
				break;
			}
		}
		if(tmpx==1){
			sum+=i;
		}
	
	}
	}
	printf("Case #%d: %d\n", k+1, sum);
}
	return 0;
}
