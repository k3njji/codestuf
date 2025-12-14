#include<stdio.h>

void swap (int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int findPivotPosition(int num[], int start, int end){
	int a = start;
	int pv = num[end];

	for(int i=start; i<end; i++){
		if(num[i]<=pv){
			swap(&num[i], &num[a]);
			a++;
		}
	}
	swap(&num[a], &num[end]);
	return a;
}

void quickSort(int num[], int start, int end){
	if(start<end)
	{
		int midPosition = findPivotPosition(num, start, end);
		quickSort(num, start, midPosition-1);
		quickSort(num, midPosition+1, end);
	}
}

int main()
{
	int num[8] = {10, 30, 40, 50, 70, 90, 80};
	quickSort(num, 0, 8-1);
	
	for(int i=0; i<7; i++){
		printf("%d ", num[i]);
	}
	
	return 0;
}
