#include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	int numb[x];
	
	for(int i=0; i<x; i++){
		scanf("%d", &numb[i]);
	}
	
	for(int i=0; i<x-1; i++){
		for(int j=0; j<x-i-1; j++){
			if(numb[j]>numb[j+1]){
				int temp=numb[j];
				numb[j]=numb[j+1];
				numb[j+1]=temp;
			}
		}
	}
	int result[x];
	
	for(int i=0; i<x-1; i++){
		result[i]=numb[i+1]-numb[i];
	}
	
	int max;
	
	for(int i=0; i<x-1; i++){
		if(result[i]<result[i+1]){
			max=result[i+1];
		}
	}
	
	int count=0;
	
	for(int i=0; i<x; i++){
		if(max==result[i]){
			count++;
		}
	}
	int counter=0;
	
		for(int i=0; i<x; i++){
			if(max==result[i]){
				counter=1;
				if(i%2==0 && i!=0 && counter==1){
				printf(" ");
			}
				printf("%d %d", numb[i], numb[i+1]);
			}
		}
		printf("a\n");

	return 0;
}

//10 45 9 3 -6 100 68 -57 23 -11 -25
