#include<stdio.h>

int main()
{
	
	long long y;
	scanf("%lld", &y);
	for(long long b=0; b<y; b++){
	long long x;
	scanf("%lld", &x);
	long long arr[x];
	for(long long i=0; i<x; i++){
		scanf("%lld", &arr[i]);
	}
	long long count;
	long long save = 0;
	for(long long j=0; j<x; j++){
		for(long long k=j+1; k<x; k++){
			count = arr[j]+arr[k];
			if(count>=save){
				save=count;
			}
			}
		}
		printf("Case #%lld: %lld\n", b+1, save);
	}
	
	return 0;
}
