#include<stdio.h>
#include<string.h>

int main()
{
	int x;
	scanf("%d", &x);
	
	for(int y=0; y<x; y++){
	
	char number[100];
	scanf("%s", &number);
	int len;
	len=strlen(number);
	int panj = len/2;
	int a=0;
	if(len%2==1){
		printf("NO\n");
	}else if(len%2==0){
	for(int i=0; i<panj; i++){
		if(number[i]!=number[panj+i]){
			a++;
			break;
		}
		}
		if(a==1){
		printf("NO\n");
	}else{
		printf("YES\n");
	}
	}
	}
	
	
	return 0;
}
