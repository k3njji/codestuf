#include<stdio.h>


int main()
{
	int t;
	scanf("%d", &t);
	for(int j=1; j<=t; j++){
		
	long long x, a;
	long long total = 1;
	unsigned long long fact[100];
	scanf("%lld", &x);
	
	for(int p=0; p<x; p++){
		scanf("%d", &a);
	if(a==1){
		fact[a]=1;
		total*=fact[a];
	}else{
		for(int i=1; i<=a; i++){
			fact[i]=fact[i-1]*i;
    		fact[i]=fact[i]%1000000007;
    		total=total * fact[i];
		}
	}
}
	printf("Case #%d: %lld\n", j, total);
}
	return 0;
}
