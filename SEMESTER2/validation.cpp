#include<stdio.h>
#include<string.h>

int main()
{
	char string[30];
	scanf("%s", string); getchar();
	int cek=0;
	
	for(int i=0; i<strlen(string); i++){
		if(string[i]=='@'){
			cek++;
		}
	}
	
	char ceker[5]={NULL};
	char ceker2[5]={NULL};
	
	int len = strlen(string);
	for(int i=len-5; i<len; i++){
		ceker[i] = string[i];
	}
	
	for(int i=len-6; i<len; i++){
		ceker2[i] = string[i];
	}
	
	printf("%s %s", ceker, ceker2);
	
	
	return 0;
}
