#include<stdio.h>

void swapValue(int *x, int *y){
	int tmp = *x;
	*x = *y;
	*y= tmp;
}

void printArray(int num[], int size){
	for(int i=0; i<size; i++){
		printf("%d ", num[i]);
	}
	puts(" ");
}

void bubbleSort(int num[], int size){
	for(int i=0; i<size-1; i++){
		printf("iteration %d\n", i);
		for(int j=0; j<size-i-1; j++){
			if(num[j]<num[j+1]){
//				//swap
//				//swapping by value
//				int tmp=sum[j];
//				num[j]=num[j+1];
//				num[j+1]=num[j+1];

//				swap by reference
					swapValue(&num[j], &num[j+1]);
			}
		}
		printArray(num, size);
	}
}

void Selectionsort (int num[], int size){
	for( int i=0; i<size-1; i++){
		int minIdx = i;
		printf("iteration %d\n", i);
		printf("minIdx %d\n", minIdx);

		for( int j=i+1; j<size; j++){
			if(num[minIdx]>num[j]){
				minIdx=j;
			}
		}
		swapValue(&num[i], &num[minIdx]);
		printArray(num, size);
	}
}

int main(){
	int num[]={5, 3, 19, 1, 27, 13};
	int size = sizeof(num)/sizeof(num[0]);
	puts("before");
	printArray(num, size);
	bubbleSort(num, size);
	puts("after");
	printArray(num, size);
}
