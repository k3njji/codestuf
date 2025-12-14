#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	char title[1000];
	int len;
	
	for (int y=1; y<=x; y++){
	
	scanf("%s", &title);
	len=strlen(title);
	
	printf("Case #%d : ", y);
	
	for(int i=len-1; i>=0; i--){
		printf("%c", title[i]);
	}
	
	printf("\n");
}
	return 0;
}
