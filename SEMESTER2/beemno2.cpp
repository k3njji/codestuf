#include<stdio.h>
#include<string.h>

void print(char string[], int count){
	count = count-1;
	printf("%c", string[count]);
	
	if(count==0){
		printf("\n");
		return;
	}
	
	print(string, count);
}

int main()
{
	int x;
	scanf("%d", &x); getchar();
	
	for(int i=1; i<=x; i++){
		char string[1100] = {NULL};
		scanf("%[^\n]", string); getchar();
		printf("Case #%d: ", i);
		print(string, strlen(string));
	}
	
	return 0;
}
