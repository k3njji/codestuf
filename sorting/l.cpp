#include<stdio.h>

void merge(int arr[], int left, int middle, int right){
 	int leftN = middle-left+1;
	int rightN = right-middle;
 	
 	int leftArr[leftN], rightArr[rightN];
 	
 	for(int i=0; i<leftN; i++){
 		leftArr[i]=arr[left+i];
	 }
	 for(int i=0; i<rightN; i++){
 		rightArr[i]=arr[middle+i+1];
	 }
	 
	 int leftCounter=0, rightCounter=0, arrCounter=left;
	 
	 while(leftCounter < leftN && rightCounter <rightN){
	 	if(leftArr[leftCounter] < rightArr[rightCounter]){
	 		arr[arrCounter++] = leftArr[leftCounter++];
		 }else{
		 	arr[arrCounter++] = rightArr[rightCounter++];
		 }
	 }
	 //ketika ini selesai (antara left dan right) pasti ada sisanya indexnya jadi:
	 while(leftCounter < leftN){
	 	arr[arrCounter++] = leftArr[leftCounter++];
	 }
	 while(rightCounter < rightN){
	 	arr[arrCounter++] = rightArr[rightCounter++];
	 }
	 
 }

void mergeSort(int numb[], int left, int right){
	if(left<right){
		int middle = left+(right-left)/2;
		mergeSort(numb, left, middle);
		mergeSort(numb, middle+1, right);
		merge(numb, left, middle, right);
	}
}
int binarySearch(int numb[], int q, int left, int right){
	if(right<left){
		return -1;
	}else{
		int mid = left+(right-left)/2;
		if(numb[mid]==q){
			return mid;
		}else if(numb[mid]>q){
			return binarySearch(numb, q, left, mid-1);
		}else if(numb[mid]<q){
			return binarySearch(numb, q, mid+1, right);
		}
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
	
	int y;
	scanf("%d", &y);
	int q;
	int z=0;
	for(int i=0; i<y; i++){
		scanf("%d", &q);
		int o = binarySearch(numb, q, z, x-1);
		if(o==-1){
			printf("%d\n", o);
		}else{
			printf("%d\n", o+1);
		}
	}
	return 0;
}
