#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
		
	for(int y = 1; y <= x; y++){
	int binary;
	scanf("%d", &binary);
	
	printf("Case #%d: ", y);
	if(binary == 0){
		printf("%d", binary);
	}else{	
		int reverse[100] = {NULL};
		int i = 0;
		while(binary > 0){
			reverse[i++] = binary%2;
			binary = binary/2;
		}
		for(int j = i-1 ; j>=0; j--){
			printf("%d", reverse[j]);
		}	
	}
	printf("\n");
}
	
	
	return 0;
}
