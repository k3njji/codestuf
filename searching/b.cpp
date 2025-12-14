#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
	fp = fopen ("testdata.in", "r");
	int x;
	fscanf(fp, "%d", &x);
	
	char nim[x][100];
	char name[x][100];
	for(int i=0; i<x; i++){
	fscanf(fp, "%s %[^\n]", &nim[i], &name[i]);
	}

	int test;
	fscanf(fp, "%d", &test);
	for(int i=1; i<=test; i++){
		char input[20];
		fscanf(fp, "%s", &input);
		int flag=0;
		for(int j=0; j<x; j++){
			if(strcmp(input, nim[j])==0){
				printf("Case #%d: %s\n", i, name[j]);
				flag=1;
				continue;
			}
		}
		if(flag==0){
			printf("Case #%d: N/A\n", i);
	}
}
fclose(fp);
	return 0;
}
