#include<stdio.h>

int main()
{
	char course[10];
	int aa, bb, cc, dd;
	int i;
	int arr[6];
	
	for(i=0; i<5; i++){
		scanf("%s %d:%d-%d:%d", &course, &aa, &bb, &cc, &dd);
		arr[i] = course aa:bb-cc:dd;
		getchar();
	}
	
	for(i=0; i<5; i++){
		printf("%d", arr[i]);
	}
	
}
