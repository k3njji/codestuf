#include<stdio.h>

char word[101][101];

void flooding(int a,int b){
	if(word[a+1][b]=='.'){
		word[a+1][b]='a';
		flooding(a+1,b);
	}
	if(word[a-1][b]=='.'){
		word[a-1][b]='a';
		flooding(a-1,b);
	}
	if(word[a][b+1]=='.'){
		word[a][b+1]='a';
		flooding(a,b+1);
	}
	if(word[a][b-1]=='.'){
		word[a][b-1]='a';
		flooding(a,b-1);
	}
}

int main()
{
	int o;
	scanf("%d", &o);
	getchar();
	for(int e=1; e<=o; e++){
		
	int x, y, a, b;
	scanf("%d %d", &x, &y);
	getchar();
	
	for(int i=0; i<x; i++){
			scanf("%s", &word[i]);
			getchar();
	}
	
	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			if(word[i][j]=='S'){
				a=i;
				b=j;
			}
		}
	}
	int count=0;
	flooding(a, b);

	for(int i=0; i<x; i++){
		for(int j=0; j<y; j++){
			if(word[i][j]=='a'){
				count++;
			}
			word[i][j]='#';
		}
	}
	printf("Case #%d: %d\n", e, count);
}
	
	return 0;
}


