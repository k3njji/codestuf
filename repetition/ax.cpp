#include<stdio.h>

int main()
{
	
	long long x;
	scanf("%lld", &x);
	long long arr[x];
	long long temp=0;
	
	for(int i=0; i<x; i++){
		scanf("%lld", &arr[i]);
		if(arr[i]>=0){
			temp+=arr[i];	
		}else{
		}
	}
	printf("%lld\n", temp);
	
	return 0;
}
