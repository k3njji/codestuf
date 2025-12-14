#include<stdio.h>
#include<string.h>

struct data{
	char name[55];
	int numb;
};

void merge(struct data arr[], int start, int mid, int end){
	int left = mid-start+1;
	int right = end - mid;
	
	struct data tempLeft[left], tempRight[right];
	
	for(int i=0; i<left; i++){
		tempLeft[i] = arr[start+i];
	}
	
	for(int i=0; i<right; i++){
		tempRight[i] = arr[mid+i+1];
	}
	
	int leftCount = 0;
	int rightCount = 0;
	int arrCount = start;
	
	while(leftCount < left && rightCount < right){
		if(tempLeft[leftCount].numb < tempRight[rightCount].numb){
			arr[arrCount++] = tempLeft[leftCount++];
		}else if(tempLeft[leftCount].numb == tempRight[rightCount].numb){
			if(strcmp(tempLeft[leftCount].name, tempRight[rightCount].name) < 0){
			arr[arrCount++] = tempLeft[leftCount++];	
			}else{
				arr[arrCount++] = tempRight[rightCount++];
			}
		}else{
			arr[arrCount++] = tempRight[rightCount++];
		}
	}
	
	while(leftCount < left){
		arr[arrCount++] = tempLeft[leftCount++];
	
	}
	
	while(rightCount < right){
		arr[arrCount++] = tempRight[rightCount++];
	}
}

void mergeSort(struct data arr[], int start, int end){
	if(start<end){
		int mid = start + (end-start)/2;
		mergeSort(arr, start, mid);
		mergeSort(arr, mid+1, end);
		merge(arr, start, mid, end);
	}
}


int main()
{
	int y;
	scanf("%d", &y); getchar();
	
	for(int j=1; j<=y; j++){
		
	int x;
	scanf("%d", &x); getchar();
	struct data arr[x];
	for(int i=0; i<x; i++){
		scanf("%[^ ] %d", &arr[i].name, &arr[i].numb);
		getchar();
	}
	
	mergeSort(arr, 0, x-1);
	printf("Case #%d:\n", j);
	for(int i=0; i<x; i++){
		printf("%s - %d\n", arr[i].name, arr[i].numb);
	}
}
	
	return 0;
}

//2
//3
//andi#30
//rudi setiawan#50
//aben#30
//5
//andi#70
//rudi setiawan#50
//aben#70
//rony sinardi#50
//kurniati#40
