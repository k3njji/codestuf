#include<stdio.h>
/* Merge Sort
 1. mecah array ke unit terkecil (saampe cmn 1 biji)
 [mergeSort(array, left, right) - recursive
 a. cari middle (titik potong)
 b. merge array
 2. Ngegabungin array (logic sorting)
 merge(array left, middle, right)
 a. cari jumlah angka array kiri dan array kanan
 b. declare array temporary untuk kanan dan kiri
 c. ngecopy data dari array sumber ke array temporary
 d. kita bikin counter / petunjuk
 		i. array kiri
 		ii. array kanan
 		iii. array smber
 e. kita compare array kiri dan aray kanan
 f. kalo ada sisa, copy sisa konten arraynya ke array sumber
 -- selesai
 */
 
int n;

void print(int arr[]){
 	for(int i=0; i<n; i++){
 		printf("%d ", arr[i]);
	 }
 }

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
	 		arr[arrCounter] = leftArr[leftCounter];
	 		leftCounter++;
	 		arrCounter++;
		 }else{
		 	arr[arrCounter] = rightArr[rightCounter];
		 	rightCounter++;
		 	arrCounter++;
		 }
	 }
	 //ketika ini selesai (antara left dan right) pasti ada sisanya indexnya jadi:
	 while(leftCounter < leftN){
	 	arr[arrCounter] = leftArr[leftCounter];
	 	leftCounter++;
	 	arrCounter++;
	 }
	 while(rightCounter < rightN){
	 	arr[arrCounter] = rightArr[rightCounter];
	 	rightCounter++;
	 	arrCounter++;
	 }
	 
 }
 
 
 void mergeSort(int arr[], int left, int right){
 		// left dan right adalah index
 		
 		if(left<right){
 			/*
 			rumus middle = 
 			a. left + (left+right) / 2 (coba pakai rmumus a)
 			b. (left + right)/ 2
 			*/
 			
 			int middle = left+(right-left)/2;
 			mergeSort(arr, left, middle); // sisi kiri
 			mergeSort(arr, middle+1, right); // sisi kanan
 			merge(arr, left, middle, right);
		 }
 }
 
int main()
{
	int arr[10]={31, 48, 30, 5, 24, 43, 22, 45, 34, 3};
	n=10;
	printf("%d\n", n);
	print(arr);
	puts("");
	mergeSort(arr, 0, n-1);
	print(arr);
	return 0;
}
