#include<stdio.h>

int main()
{

	int y;
	scanf("%d", &y);
	for(int b=1; b<=y; b++){

	int x;
	scanf("%d", &x);
	int arr[x];
	
	for(int i=0; i<x; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<x; i++){
		if(arr[0]<arr[i]){
			arr[0]=arr[i];
		}
	}
	for(int i=0; i<x; i++){
		if(arr[1]<arr[i] && arr[i]<arr[0]){
			arr[1]=arr[i];
		}
	}
	int sum = arr[0]+arr[1];
	printf("Case #%d: %d\n", b, sum);
}

	return 0;
}
