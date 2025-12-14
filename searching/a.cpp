#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
	fp = fopen ("testdata.in", "r");
	int x;
	fscanf(fp, "%d\n", &x);
	char input[x+1][150];
	char output[x+1][150];
	
	for(int i=0; i<x; i++){
		fscanf(fp, "%[^#]#%s\n", &input[i], &output[i]);
	}
	
	int test;
	fscanf(fp, "%d\n", &test);
	for(int i=0; i<test; i++){
		char temp[1000];
		fscanf(fp, "%[^\n]\n", &temp);
		
		int len=strlen(temp);
		
		char word[1000][1000]={0};
		int a=0, b=0;
		for(int j=0; j<len; j++){
			if(temp[j]==' '){
				a++;
				b=0;
			}else{
				word[a][b]=temp[j];
				b++;
			}
		}
		
		printf("Case #%d:\n", i+1);
//		for(int j=0; j<=a; j++){
//			printf("%s\n", word[j]);
//		}
		for(int j=0; j<=a; j++){
			int flag=0;
			for(int k=0; k<x; k++){
				if(strcmp(word[j], input[k])==0){
					printf("%s", output[k]);
					if(j!=a){
						printf(" ");
					}
					flag=1;
					continue;
				}
			}
			if(flag==0){
				printf("%s", word[j]);
				if(j!=a){
					printf(" ");
				}
			}
		}
		printf("\n");
}
	return 0;
}
