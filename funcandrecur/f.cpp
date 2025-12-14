#include<stdio.h>
#include<string.h>

void printWord(int x, char word[]){
	for(int i=x-1; i>=0; i--){
		printf("%c", word[i]);
	}
}

int main()
{
	int y;
	scanf("%d", &y); getchar();
	for(int j=1; j<=y; j++){
	char word[1000];
	scanf("%[^\n]s", &word); getchar();
	int len=strlen(word);
	
	printf("Case #%d: ", j);
	printWord(len, word);
	printf("\n");
}
	return 0;
}
