#include<stdio.h>

int main()
{
	long long x;
	scanf("%lld", &x);
	long long numb[x];
	
	for(long long i=0; i<x; i++){
		scanf("%lld", &numb[i]);
	}
	
	for(long long i=0; i<x-1; i++){
		for(long long j=0; j<x-i-1; j++){
			if(numb[j]>numb[j+1]){
				long long temp=numb[j];
				numb[j]=numb[j+1];
				numb[j+1]=temp;
			}
		}
	}
	
	long long result[x-1];
	
	for(long long i=0; i<x-1; i++){
		result[i]=numb[i+1]-numb[i];
	}
	
	long long max=result[0];
	
	for(long long i=1; i<x-1; i++){
		if(max<result[i]){
			max=result[i];
		}
	}
	
long long ans[x];
	long long y=0;
	for(long long i=0; i<x-1; i++){
		if(max==result[i]){
			ans[y]=numb[i];
			y++;
			ans[y]=numb[i+1];
			y++;
		}
	}
	
	for(long long i=0; i<y; i++){
		if(i!=0){
			printf(" ");
		}
		printf("%lld", ans[i]);
	}
printf("\n");
	return 0;
}
