#include<stdio.h>


void merge(int numb[], int left, int mid, int right){
	int lefty = mid - left + 1;
	int righty = right - mid;
	
	int leftArr[lefty];
	int rightArr[righty];
	
	for(int i=0; i<lefty; i++){
		leftArr[i]=numb[left+i];
	}
	
	for(int i=0; i<righty; i++){
		rightArr[i]=numb[mid+i+1];
	}
	
	int leftC = 0, rightC = 0, arrC = left;
	
	while(leftC < lefty && rightC < righty){
		if(leftArr[leftC] < rightArr[rightC]){
			numb[arrC] = leftArr[leftC];
			arrC++;
			leftC++;
		}else{
			numb[arrC] = rightArr[rightC];
			arrC++;
			rightC++;
		}
	}
	
	while(leftC < lefty){
		numb[arrC] = leftArr[leftC];
		arrC++;
		leftC++;
	}
	while(rightC < righty){
		numb[arrC] = rightArr[rightC];
		arrC++;
		rightC++;
	}
}

void mergeSort(int numb[], int left, int right){
	if(left<right){
		int mid = left+(right-left)/2;
		
		mergeSort(numb, left, mid);
		mergeSort(numb, mid+1, right);
		merge(numb, left, mid, right);
	}
}

int main()
{
	int x;
	scanf("%d", &x);
	
	int numb[x];
	
	for(int i=0; i<x; i++){
		scanf("%d", &numb[i]);
	}
	
	mergeSort(numb, 0, x-1);
	

	
	int sum= x/2;
	for(int i=sum+1; i<x; i++){
		printf("%d", numb[i]);
		if(i!=x-1){
			printf(" ");
		}
	}
	printf("\n");
	
	return 0;
}
