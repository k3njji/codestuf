#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "r");
	int q;
	fscanf(fp, "%d\n", &q);
	for(int z=0; z<q; z++){
	char word[101];
	fscanf(fp, "%[^\n]\n", &word);
	int len = strlen(word);
	int arr[91] = {0};
	for(int i=0; i<len; i++){
		arr[word[i]]++;
	}
	
	int x;
	fscanf(fp, "%d\n", &x);
	int v[91] = {0};
	for(int i=0; i<x; i++){
		char a, b;
		fscanf(fp, "%c %c\n", &a, &b);
		int f = b;
		int e = a;
		v[a]++;
		for(int j = 65; j < 91; j++){
			if(v[j]==1){
			if(e==j && j!=f){
				arr[f] = arr[j];
				arr[j] = 0;
			}
		}
		}
	}
	for(int i=65; i<91; i++){
		if(arr[i]>0){
		printf("%c %d\n", i, arr[i]);
	}
	}
}
	
	return 0;
}
