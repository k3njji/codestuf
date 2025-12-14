#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "r");
	int test;
	fscanf(fp, "%d", &test);
	for(int a=1; a<=test; a++){
	int count=0;
	int result=0;
	int x, y, z;
	fscanf(fp, "%d %d %d", &x, &y, &z);
	
	char petir[x];
	fscanf(fp, "%s", &petir);
	
	for(int i=0; i<x; i++){
		if(petir[i]=='1'){
		count++;
		if(count>=y && count<=z && petir[i+1]!='1'){
		result++;
		}
		}else{
		count=0;
		}
	}
	printf("Case #%d: %d\n", a, result);
}
	fclose(fp);
	
	return 0;
}
