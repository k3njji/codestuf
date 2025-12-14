#include<stdio.h>

int main()
{
	int b;
	scanf("%d", &b);
	for(int a=1; a<=b; a++){
		
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	int arr[x];
	for (int i=0; i<x; i++){
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<x; i++){
		if(arr[i]<=y && arr[i]>z){
			z=arr[i];
		}else{
			z;
		}
	}
	printf("Case #%d: %d\n", a, z);
}
	
	return  0;
}
