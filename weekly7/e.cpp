#include<stdio.h>
#include<string.h>
int main()
{
	char word[10001];
	scanf("%[^\n]s", &word);
	
	int len=strlen(word);
	printf("%d", len);
	
	for(int i=0; i<len-1; i++){
		if(word[i]=='I'){
			word[i]='A';
			printf("%c", word[i]);
		}
	}
	
}
