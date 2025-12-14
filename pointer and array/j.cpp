#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	for(int y=1; y<=x; y++){
	
	
	char word[1000];
	scanf("%s", &word);
	int len;
	len=strlen(word);
	printf("Case %d: %d", y, word[0]);
	
	for(int i=1; i<len; i++){
		printf("-%d", word[i]);
	}
	printf("\n");
}
	return 0;
}
