#include<stdio.h>
#include<math.h>

int main()
{
	FILE *fp;
	fp=fopen ("testdata.in", "r");
	
	int y;
	fscanf(fp, "%d\n", &y);
	
	for(int j=1; j<=y; j++){
	
	int x;
	fscanf(fp, "%d\n", &x);
	
	int numb[x]={0};
	
	int total=0;
	
	for(int i=0; i<x; i++){
		fscanf(fp, "%d ", &numb[i]);
		total+=numb[i];
	}
	int sum=0;
	
	for(int i=0; i<=x; i++){
		sum+= abs(numb[i]-numb[i-1]);
		if(numb[i]!=0){
			sum++;
			sum++;
		}
	}
	
	printf("Case #%d: %d %d\n", j, sum*2, total*4);
}
	return 0;
}
