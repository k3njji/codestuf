#include<stdio.h>
#include<string.h>

int main()
{
	char word[1000];
	scanf("%[^\n]s", &word);
	
	int len=strlen(word);
	
	for(int i=0; i<len; i++){
		if(word[i]=='a'){
			word[i]='%';
			printf("%c", word[i]);
		}else if(word[i]>='a' && word[i]<='z'){
			printf("%c", word[i]+3);
		}
		}
	
	
	
	
	
	return 0;
}
