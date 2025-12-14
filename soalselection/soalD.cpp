#include<stdio.h>
int main()
{
	int d;
	int m, n;
	scanf("%d", &d);
	int arr[1000];
	int i=1;
	
	for(i; i<=d; i++){
		scanf("%d %d", &n, &m);
		int sum = n/2+m/2+(n+m)/2;
		printf("%d\n", sum);
		
		if(sum%2==0){
			printf("Case #%d: Party time!\n", i);
		} else {
			printf("Case #%d: Need more frogs\n", i);
		}
		getchar();
	}
	
	return 0;
}
