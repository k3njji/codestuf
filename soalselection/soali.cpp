#include<stdio.h>
int main()
{
	int t, a, b, c;
	scanf("%d", &t);
	int arr[1000];
	
	for(int i=1; i<=t; i++){
	scanf("%d %d %d", &a, &b, &c);
	int sum = a*b/100;
	if(sum>c){
		printf("Case #%d: %d\n", i, c);
	} else {
		printf("Case #%d: %d\n", i, sum);
	}
	arr[i];
	getchar();
}
return 0;
	
}
