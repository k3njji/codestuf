#include<stdio.h>
#include<string.h>

int main()
{
	char word[1000];
	scanf("%s", &word);
	int len=strlen(word);
	
	for(int i=0; i<len; i++){
		if(word[i] == 'A' ){
			printf("A");
		}else if(word[i] == 'E' ){
			printf("E");
		}
	}
	
	
	
	return 0;
}
