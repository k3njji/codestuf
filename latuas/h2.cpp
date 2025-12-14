#include<stdio.h>

void merge(int numb[], int start, int mid, int end){
	int left = mid - start - 1;
	int right = end - mid;
	
	int leftTemp[left], rightTemp[right];
	
	for(int i=0; i<left; i++){
		leftTemp[i] = numb[start+i];
	}
	
	for(int i=0; i<right; i++){
		rightTemp[i] = numb[mid+1+i];
	}
	
	int leftCounter=0, rightCounter=0, arrCounter=start;
	
	while(leftCounter < left && rightCounter < right){
		if(leftTemp[leftCounter] < rightTemp[rightCounter]){
			numb[arrCounter++] = leftTemp[leftCounter++];
		}else{
			numb[arrCounter++] = rightTemp[rightCounter++];
		}
	}
	
	while(leftCounter < left){
		numb[arrCounter++] = leftTemp[leftCounter++];
	}
	
	while(rightCounter < right){
		numb[arrCounter++] = rightTemp[rightCounter++];
	}
}



void mergeSort(int numb[], int left, int right){
	if(left<right){
		int mid = left + (right-left)/2;
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

	for(int i=0; i<x; i++){
		printf("%d ", numb[i]);
	}

	return 0;
}
