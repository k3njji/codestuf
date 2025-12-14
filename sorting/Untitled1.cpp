#include<stdio.h>

/*SORTING
bubble sort
selection sort
insertion sort

given an array of int = (5 3 19 1 27 13}
Ascending: 1 3 5 13 19 27
Decending 27 19 13 5 3 1
*/

int main()
{
	int numb[6];
	for(int i=0; i<6; i++){
		scanf("%d", &numb[i]);
	}
	int sum=6*6;
	int temp=0;
	for(int i=0; i<sum; i++){
		for(int j=0; j<sum; j++){
			if(numb[i]>numb[j]){
				temp=numb[i];
				numb[i]=numb[j];
				numb[j]=temp;
			}
		}
	}
	
	for(int i=0; i<6; i++){
		printf("%d ", numb[i]);
	}
	
	
	
	return 0;
}
