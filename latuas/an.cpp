#include<stdio.h>

int main()
{
	int y;
	scanf("%d", &y);
	
	for(int a=1; a<=y; a++){
		
	long long int x;
	scanf("%lld", &x);
	
	long long int numb[x+1];
	
	for(long long int i=0; i<x; i++){
		scanf("%lld", &numb[i]);
	}
	
	long long int count=0;
	long long int check[x]={0};
	
	for(long long int i=0; i<x; i++){
		if(check[i]==1){
			continue;
		}else{
			count++;
		}
			for(long long int j=0; j<x; j++){
				if(numb[i] == numb [j]){
					check[j]=1;
				}
		}
	}
	printf("Case #%d: %lld\n", a, count);
}
	
	
	
	return 0;
}
