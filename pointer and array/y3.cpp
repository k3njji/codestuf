#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	getchar();
	char word[1000];
	char temp[1000];
	scanf("%[^\n]s", &word);

	int a, b;
	
	for(int i=1; i<=x; i++){
		scanf("%d %d", &a, &b);
		a--;
		b--;
		strcpy(temp, word);
		for(int j=a, k=b; j<=b, k>=a; j++, k--){
			word[a]=temp[b];
		}
	}
	printf("%s", word);
	return 0;
}
