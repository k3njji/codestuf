#include<stdio.h>
#include<string.h>


int main()
{
	int o;
	scanf("%d", &o);
	getchar();
	for(int l=1; l<=o; l++){
	char word[1000];
	scanf("%[^\n]s", &word);
	getchar();
	
	int len=strlen(word);
	
	int x;
	scanf("%d", &x);
	getchar();
	char subs, y;
	
	for(int i=0; i<x; i++){
		scanf("%c", &y);
		getchar();
		scanf("%c", &subs);
		getchar();
			for(int j=0; j<len; j++){
				if(word[j]==y){
					word[j]=subs;
				}
			}
	}
	printf("Case #%d: %s\n", l, word);
}
	
	return 0;
}
