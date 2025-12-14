#include<stdio.h>

void swap (int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void merge(int num[], int start, int mid, int end){
	int l = mid-start+1;
	int r = end-mid;
	int left[l], right[r];
	
	for(int i=0; i<l; i++){
		left[i]=num[start+i];
	}
	
	for(int i=0; i<r; i++){
		right[i]=num[mid+1+i];
	}
	
	int a = start, b=0, c=0;
	
	while(b<l && c<r){
		if(left[b]<=right[c]){
			num[a]=left[b];
			a++;
			b++;
		}else{
			num[a]=right[c];
			a++;
			c++;
		}
	}
	
	while(b<l){
		num[a]=left[b];
		a++;
		b++;
	}
	
	while(c<r){
		num[a] = right[c];
		a++;
		c++;
	}
}

void mergeSort(int num[], int start, int end)
{
	if(start<end){
		int mid = (start+end)/2;
		mergeSort(num, start, mid);
		mergeSort(num, mid+1, end);
		merge(num, start, mid, end);
	}
}

int main()
{
	int num[8] = {10, 30, 40, 50, 70, 90, 80};
	mergeSort(num, 0, 8-1);
	
	for(int i=0; i<8; i++){
		printf("%d ", num[i]);
	}
	
	return 0;
}
