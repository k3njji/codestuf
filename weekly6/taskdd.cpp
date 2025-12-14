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
	int save1 = 0;
	for(int i=0; i<x; i++){
		if(arr[i]>save1){
			save1=arr[i];
		}
	}
	int save2 = 0;
	for(int i=0; i<x; i++){
		if(save2<=arr[i] && arr[i]<save1){
			save2=arr[i];
		}
	}
	printf("Case #%d: %d %d, %d\n", b, save1, save2, save1+save2);
}

	return 0;
}
