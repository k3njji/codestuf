#include<stdio.h>

int main()
{
	
	int x, a, b,sum, sum2, sum3;
//	scanf("%d", &x);
//	
//	for(int i=0; i<x; i++){
//		scanf("%d %d", &y, &z);
//		sum=y/z;
//		sum2=y%z;
//		if(sum==0){
//		printf("%d", y);
//		}else if(sum>0){
//		sum3= (sum2+sum)/z;
//		printf("Case #%d: %d\n", i+1, y+sum+sum3);
//		}
//		}
		scanf("%d %d", &a, &b);
		while(a>b){
			printf("yes");
			a--;
		}
	
	return 0;
}
