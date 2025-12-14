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
	 while(leftCounter < leftN){
	 	arr[arrCounter++] = leftArr[leftCounter++];
	 }
	 while(rightCounter < rightN){
	 	arr[arrCounter++] = rightArr[rightCounter++];
	 }
	 
 }
 
 
 void mergeSort(int arr[], int left, int right){
 		// left dan right adalah index
 		
 		if(left<right){
 			int middle = left+(right-left)/2;
 			mergeSort(arr, left, middle); // sisi kiri
 			mergeSort(arr, middle+1, right); // sisi kanan
 			merge(arr, left, middle, right);
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
	
	int result[x-1];
	
	for(int i=0; i<x-1; i++){
		result[i]=numb[i+1]-numb[i];
	}
	
	int max=result[0];
	
	for(int i=1; i<x-1; i++){
		if(max<result[i]){
			max=result[i];
		}
	}
	
int ans[x];
	int y=0;
	for(int i=0; i<x-1; i++){
		if(max==result[i]){
			ans[y]=numb[i];
			y++;
			ans[y]=numb[i+1];
			y++;
		}
	}
	
	for(int i=0; i<y; i++){
		if(i!=0){
			printf(" ");
		}
		printf("%d", ans[i]);
	}
printf("\n");
	return 0;
}
