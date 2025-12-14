#include<stdio.h>

int main()
{
	for(int i=0; i<2; i++){
	char word[21], w2rd[21], w3rd[21];
	scanf("%s %s %s", &word, &w2rd, &w3rd);
	getchar();
	printf("%sszs %sszs %sszs\n", word, w2rd, w3rd);
}
	return 0;
}
