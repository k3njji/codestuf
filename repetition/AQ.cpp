#include<stdio.h>
#include<string.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	char ipad[101];
	for(int y=1; y<=x; y++){
	scanf("%s", &ipad);
	int len=strlen(ipad);
	int a=0;
	for(int i=0; i<len; i++){
		if(ipad[i]=='.'){
			a++;
		}
		if(ipad[i]=='.'&&ipad[i+1]=='.'){
			a=0;
			break;
		}	
	}
	if(a==5){
		printf("Case #%d: YES\n", y);
	}else{
		printf("Case #%d: NO\n", y);

	}
}
	return 0;
}
