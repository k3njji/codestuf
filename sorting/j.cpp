#include<stdio.h>

int main()
{
	int b;
	scanf("%d", &b);
	for(int a=1; a<=b; a++){
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
	
	double total=0;
	for(int i=0; i<x; i++){
		total+=numb[i];
	}

	double mean = total/x;
	
	printf("Case #%d:\n", a);
	printf("Mean : %0.2lf\n", mean);
	
	if((x+1)%2==0){
	int median = (x+1)/2;
	double mediann = numb[median-1];
	printf("Median : %0.2lf", mediann);
	}else{
	int median = (x+1)/2;
	double mediann = (numb[median-1]+numb[median]);
	double result = mediann/2;
	printf("Median : %0.2lf", result);
	}
	printf("\n");
}
	return 0;
}
