#include<stdio.h>
#include<string.h>

struct data{
	char hero[250];
	int dmg;
};

void merge(struct data dota[], int start, int mid, int end){
	int left = mid - start + 1;
	int right = end - mid;
	
	struct data tempLeft[left], tempRight[right];
	
	for(int i=0; i<left ; i++){
		tempLeft[i] = dota[start+i];
	}
	
	for(int i=0; i<right ; i++){
		tempRight[i] = dota[mid+i+1];
	}
	
	int leftCount = 0;
	int rightCount = 0;
	int count = start;
	
	while(leftCount < left && rightCount < right){
		if(tempLeft[leftCount].dmg < tempRight[rightCount].dmg){
			dota[count] = tempLeft[leftCount];
			count++;
			leftCount++;
		}else if(tempLeft[leftCount].dmg == tempRight[rightCount].dmg){
			if(strcmp(tempLeft[leftCount].hero, tempRight[rightCount].hero) < 0){
				dota[count] = tempLeft[leftCount];
				count++;
				leftCount++;
			}else{
				dota[count] = tempRight[rightCount];
				count++;
				rightCount++;
			}
		}else{
			dota[count] = tempRight[rightCount];
			count++;
			rightCount++;
		}
	}
	while(leftCount < left){
		dota[count++] = tempLeft[leftCount++];
	}
	
	while(rightCount < right){
		dota[count++] = tempRight[rightCount++];
	}
	
}

void mergeSort(struct data dota[], int left, int right){
	if(left<right){
		int mid = left + (right-left)/2;
		mergeSort(dota, left, mid);
		mergeSort(dota, mid+1, right);
		merge(dota, left, mid, right);
	}
}

int main()
{
//	struct data dota[];
	int x;
	scanf("%d", &x); getchar();
	struct data dota[x];
	for(int i=0; i<x; i++){
		scanf("%s %d", &dota[i].hero, &dota[i].dmg);
		getchar();
	}
	
	mergeSort(dota, 0, x-1);
	
	char a[10];
	scanf("%s", &a);
	getchar;
	
	if(strcmp(a, "asc") == 0){
		for(int i=0; i<x; i++){
			printf("%s %d\n", dota[i].hero, dota[i].dmg);
		}
	}else{
		for(int i=x-1; i>=0; i--){
				printf("%s %d\n", dota[i].hero, dota[i].dmg);

		}
	}
	
	return 0;
}

//5
//Faceless 50
//Enchantress 35
//Slardog 45
//Sunder 52
//Tiny 55
//dsc

