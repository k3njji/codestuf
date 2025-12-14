#include<stdio.h>

int main()
{
	int k;
	scanf("%d", &k);
	
	for(int l=0; l<k; l++){
	
	int x;
	int odd=0;
	int even=0;
	
	scanf("%d", &x);
	for(int i=1; i<=x; i++){
		int y;
		scanf("%d", &y);
		if(y%2==0){
			even++;
		}else{
			odd++;
		}
		
	}
	printf("Odd group : %d integer(s).\n", odd);
	printf("Even group : %d integer(s).\n", even);
	printf("\n");
}
	return 0;
}
