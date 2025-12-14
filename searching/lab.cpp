#include<stdio.h>

void bubbleSort(int *arr, int size){
	for(int i=0; i<size-1; i++){
		for(int j=0; j<size-i-1; j++){
			if(arr[j] > arr[j+1]){
				int temp=arr[j];
				arr[j]=arr[j+1];
				arr[j+1]=temp;
			}
		}
	}
}

void printArray(int *arr, int left, int right){
	for(int i=left; i<right; i++){
		printf("%d ", arr[i]);
	}
	puts("");
}

int binarySearch(int arr[], int target, int left, int right){
	if(right<left){
		return -1;
	}else{
		//use this mid formula = left + (right-left)/2
		int mid = left + (right-left)/2;
		if(arr[mid]==target){
			return mid;
		}else if(arr[mid]> target){
			return binarySearch(arr, target, left, mid-1);
		}else{
			return binarySearch(arr, target, mid+1, right);
		}
	}
}



int main()
{
	int arr[] = {10, 3, 19, 45, 16, 11, 9};
	int size = sizeof(arr)/sizeof(arr[0]);
	//target = value that we are searching
	int target = 3;
	int idx = -1;
	// linear search -> loop through the array and check
	// wether the target is equal to the value of the index
	// unsorted
	
//	for(int i=0; i<size; i++){
//		printf("%d == %d\n", target, arr[i]);
//		if(arr[i]==target){
//			//the invalue is found
//			idx=i;
//			break;
//		}
//	}
//	
//	if(idx == -1){
//		puts("Value not Found");
//	}else{
//		printf("Value found at index %d\n", idx);
//	}
	
	
	
	// sorted
//	bubbleSort(arr, size);
//	int z;
//	for(int z=0; z<size; z++){
//		printf("%d == %d\n", target, arr[z]);
//		if(arr[z]==target){
//			printf("Value found at %d\n", z);
//			break;
//		}
//		if(z>=size){
//			puts("Value not Found");
//		}
//	}
	
	//time complexity for unsorted one is = X
	//time complexity for sorted one is = ?
	
	// BINARY SEARCH
	// ITERATIVE
	int left = 0;
	int right = size;
		bubbleSort(arr, size);
//	int flag=0;
	// 0 -> not found
	// 1 -> found
//	
//	while(left <= right){
//		printArray(arr, left, right);
//		int mid = (left+right)/2;
//		printf("mid is %d : %d\n", mid, arr[mid]);
//			if(arr[mid] == target){
//				//value if found
//				idx = mid;
//				flag=1;
//				break;
//			}else if(arr[mid] < target){
//				//target is on the second half
//				left=mid+1;
//			}else{
//				//target is on the first half
//				right=mid-1;
//			}
//	}
//	if(flag==0){
//		puts("not found");
//	}else{
//		printf("value found at %d", idx);
//	}
	// time complexity for binary search is log2(n)
	
	//recursive binary search
	int x = binarySearch(arr, target, left, right);
	if(x==-1){
		puts("value not found");
	}else{
		printf("the value is at %d", x);
	}
	
	
//	//interpolation search
//	//advance binary search
//	int left=0;
//	int right = size-1;
//	bubbleSort(arr, size);
//	
//	int flag=0;
//	while(left<=right && target <= arr[right] && target>= arr[left]){
//		printArray(arr, left, right);
//		int mid = left + (target-arr[left])*(right-left) / (arr[right] - arr[left]);
//		printf("mid is %d : %d\n", mid, arr[mid]);
//		if(arr[mid] == target){
//			printf("Value found at %d\n", mid);
//			flag=1;
//			break;
//		}else if(arr[mid] < target){
//			//second half
//			left = mid+1;
//		}else{
//			//first half
//			right = mid-1;
//		}
//	}
//	
//	if(flag==0){
//		puts("value not found");
//	}
	
	//time complexity for interpolation is log2(log2(n))
	
	return 0;
}
