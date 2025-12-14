#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	for(int y=1; y<=x; y++){
	
	char word[501];
	scanf("%s", &word);
	int len;
	len=strlen(word);
	
	int a=0;
	
	for(int i=0; i<len-1; i++){
		if(word[i]!=word[len-i-1]){
			a++;
			break;
			}
		}
		printf("Case #%d: ", y);
		
		if(a==0){
			printf("Yay, it's a palindrome\n");
		}else{
			printf("Nah, it's not a palindrome\n");
		}
}
	return 0;
}
