#include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	long long int numb[x];
	for(int i=0; i<x; i++){
		scanf("%lld", &numb);
	}
	
	int check[x]={0};
	int count[x]={0};
	int k=0;
	for(int i=0; i<x; i++){
		if(check[i]==1){
			continue;
		}
		for(int j=0; j<x; j++){
			if(numb[i]==numb[j]){
				count[numb[j]]++;
				check[j]=1;
			}
		}
	}
	
	for(int i=0; i<x; i++){
		printf("%lld ", count[i]);
	}
	
	
	
	return 0;
}
