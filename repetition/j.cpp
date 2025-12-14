#include<stdio.h>

int main()
{
	int x, y, z, i;
	scanf("%d", &x);
	
	for(i=0; i<x; i++){
		scanf("%d", &y);
		getchar();
		long long arr[y];
		long long k = 0;
		
		for(z=0; z<y; z++){
			scanf("%lld", &arr[z]);
			k+=arr[z];
		}
		printf("Case #%d: %lld\n", i+1, k);
	}
	return 0;
}
