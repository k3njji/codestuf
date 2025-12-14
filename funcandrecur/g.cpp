#include<stdio.h>
#include<string.h>

int palin(int x, char word[]){
	int sum=0;
	
	for(int i=0; i<x; i++){
		if(word[i]=='s'){
			sum++;
		}
	}
	return sum;
}

int main()
{
	int y;
	scanf("%d", &y);
	getchar();
	
	for(int i=1; i<=y; i++){
	char word[1000];
	scanf("%[^\n]s", &word);
	getchar();
	
	int len=strlen(word);
	int sum=palin(len, word);
	
	printf("Case #%d: ", i);
	if(sum==len){
		printf("yes\n");
	}else{
		printf("no\n");
	}
}
	return 0;
}
