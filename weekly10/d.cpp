#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	getchar();
	for(int j=1; j<=x; j++){
	char word[1001];
	scanf("%[^\n]s", &word);
	getchar();
	
	printf("Case #%d: ", j);
	int len=strlen(word);
	for(int i=0; i<len; i++){
		if(word[i]=='a' || word[i]=='i' || word[i]=='e' || word[i]=='u' || word[i]=='o' || word[i]=='A' || word[i]=='I' || word[i]=='U' || word[i]=='E' || word[i]=='O'){
			continue;
		}else{
			printf("%c", word[i]);
		}
	}
	printf("\n");
}
	
	return 0;
}
