#include<stdio.h>

int main()
{
	int b;
	scanf("%d", &b);
	for(int c=1; c<=b; c++){
	int x;
	scanf("%d", &x);
	int y = x-1;
	long long arr[x];
	for(int i=0; i<x; i++){
		scanf("%lld", &arr[i]);
	}
	long long a[x];
	for(int i=0; i<x-1; i++){
		if(arr[i]<arr[i+1]){
			a[i]=arr[i+1]-arr[i];
		}else{
			a[i]=arr[i]-arr[i+1];
		}
	}
	long long smallest = a[0];
	for(int i=0; i<x-1; i++){
		if(a[i]<smallest){
			smallest = a[i];
		}
	}
	printf("Case #%d: %lld\n", c, smallest);
}
	return 0;
}
