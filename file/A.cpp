#include<stdio.h>
#include<string.h>

int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "r");
	
	int x;
	fscanf(fp, "%d\n", &x);
	
	char name[x][41];
	char rose[x][41];
	
	for(int i=0; i<x; i++){
		fscanf(fp, "%[^#]#%[^\n]\n", &name[i], &rose[i]);
	}
	
	for(int i=0; i<x; i++){
		printf("%s#%s\n", name[i], rose[i]);
	}
	
	int y;
	fscanf(fp, "%d\n", &y);
	
	for(int i=0; i<y; i++){
		char nama[40];
		fscanf(fp, "%s\n", &nama);
		int flag=0;
		
		for(int j=0; j<x; j++){
			if(strcmp(nama, name[j])==0){
				printf("Case #%d: %s\n", i+1, rose[j]);
				flag=1;
			}
		}
		
		if(flag==0){
			printf("Case #%d: N/A\n", i+1);
		}
	}
	fclose(fp);
	return 0;
}
