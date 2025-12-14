#include<stdio.h>
#include<string.h>
int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "r");
	
	int test;
	fscanf(fp, "%d\n", &test);
	
		char O = {'O'};
		char I = {'I'};
		char E = {'E'};
		char A = {'A'};
		char S = {'S'};
		char G = {'G'};
		char T = {'T'};
		char B = {'B'};
		
	for(int i=1; i<=test; i++){
		int x;
		fscanf(fp, "%d\n", &x);
		
		char word[1001];
		fscanf(fp, "%[^\n]\n", &word);
		
		int len=strlen(word);
		
		for(int j=0; j<len; j++){
			if(word[j]=='0'){
				word[j]=O;
			}else if(word[j]=='1'){
				word[j]=I;
			}else if(word[j]=='3'){
				word[j]=E;
			}else if(word[j]=='4'){
				word[j]=A;
			}else if(word[j]=='5'){
				word[j]=S;
			}else if(word[j]=='6'){
				word[j]=G;
			}else if(word[j]=='7'){
				word[j]=T;
			}else if(word[j]=='8'){
				word[j]=B;
			}
	}
	printf("Case #%d: ", i);
	for(int j=0; j<len; j++){
		if(word[j]>=65 && word[j]<=90){
			word[j]=word[j]-x;
			if(word[j]<65){
				printf("%c", word[j]+26);
			}else{
				printf("%c", word[j]);
			}
		}else{
			printf("%c", word[j]);
		}
	}
	printf("\n");
}
	return 0;
}
