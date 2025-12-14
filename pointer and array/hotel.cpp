#include<stdio.h>

int main(){
	
	int x;
	scanf("%d", &x);
	long long number[x];
	
	for(int i=0; i<x; i++){
		scanf("%lld", &number[i]);
	}
	
	for(int i=0; i<x; i++){
		if(number[i]==-1){
			continue;
		}
		for(int k=i+1; k<x; k++){
			if(number[i]==number[k]){
				number[i]=-1;
			}
		}
	}
	int a=0;
	for(int i=0; i<x; i++){
		if(number[i]>0){
			a++;
		}
	}
	printf("%d\n", a);
	return 0;
}
