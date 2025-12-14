#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	getchar();
	char numb[1000];
	scanf("%[^\n]s", &numb);
	getchar();
	
	int len=strlen(numb);
	
	char j, k;
	
	for(int i=0; i<x; i++){
		scanf("%c %c", &j, &k);
		getchar();
		for(int a=0; a<len; a++){
			for(int b=0; b<len; b++){
				if(numb[a]==j && numb[b]==k){
					numb[a]=k;
					numb[b]=j;
				}
			}
		}
	}
	printf("%s", numb);
	
	
	
	return 0;
}
