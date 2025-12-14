#include<stdio.h>

int main()
{
	
	int y;
	scanf("%d", &y);
	for(int h=0; h<y; h++){
	
	
	int x;
	scanf("%d", &x);
	int arr[x];
	
	for(int i=0; i<x; i++){
		scanf("%d", &arr[i]);
	}
	int save1 = 0;
	for(int j=0; j<x; j++){
		if(arr[j]>save1){
			save1=arr[j];
		}
	}
	int save2 = 0;
	for(int k=0; k<x; k++){
		if(arr[k]>save2 && arr[k]<save1){
			save2=arr[k];
		}
	}
	printf("Case #%d: %d\n",h+1, save1+save2);
	
}
	return 0;
}
