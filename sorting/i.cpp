#include<stdio.h>
#include<math.h>

int main()
{
	int a;
	scanf("%lld", &a);
	for(long long int b=1; b<=a; b++){
	
	long long int x;
	scanf("%lld", &x);
	long long int numb[501] = {0};
	
	for(long long int i=0; i<x; i++){
		scanf("%lld", &numb[i]);
	}
	
	long long int sum = x/2;
	
	for(long long int i=0; i<x-1; i++){
		for(long long int j=0; j<x-i-1; j++){
			if(numb[j]>numb[j+1]){
				long long int temp=numb[j];
				numb[j]=numb[j+1];
				numb[j+1]=temp;
			}
		}
	}
	
	long long int result[251]={0};
	long long int q=0;
	for(long long int i=0; i<x; i++){
		if(i+1==sum || i==x-1){
			continue;
		}else if(numb[i+1]!=0){
			result[q]= abs(numb[i]-numb[i+1]);
			q++;
		}
	}
	
	for(long long int i=0; i<q; i++){
		if(result[0]<result[i]){
			result[0]=result[i];
		}
	}

	printf("Case #%lld: %lld\n", b, result[0]);
}
	
	
	return 0;
}
