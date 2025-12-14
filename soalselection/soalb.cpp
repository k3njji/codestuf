#include<stdio.h>

int main()
{
	int d, a, b ;
	scanf("%d", &d);
	int arr[1000];
	
	for(int i=1; i<=d; i++){
		scanf("%d %d", &a, &b);
		if(a>b){
			printf("Case #%d: Go-Jo\n", i);
		} else {
			printf("Case #%d: Bi-Pay\n", i);
		}
		arr[i];
		getchar();
	}
	
	
	return 0;
}
