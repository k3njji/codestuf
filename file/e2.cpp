#include <stdio.h>
#include<math.h>
int main(){
	
	FILE *fp = fopen("testdata.in","r");
	
	int limit;
	int limit2;
	fscanf(fp,"%d\n",&limit);
	for(int i=0;i<limit;i++){
		int num[100]={0};
		int area=0;
		int peri=0;
		int x=0;
		int left=0;
		fscanf(fp,"%d\n",&limit2);
		for(int j=0;j<limit2;j++){
			fscanf(fp,"%d",&num[j]);
			if(num[j]==0){
				x=x;
			}
			else{
				x++;
				if(x==1){
					left = num[j];
				}
			}
		}
		for(int j=0;j<limit2;j++){
			area = area + (num[j]*2)*2;
		}
		peri = (x+x+left+num[limit2-1]);
		printf("peri 1: %d\n",peri);
		for(int j=0;j<limit2-1;j++){
			peri = peri + abs(num[j]-num[j+1]);
//			printf("peri 2: %d\n",peri);
		}
		peri=peri*2;
		printf("Case #%d: %d %d\n",i+1,peri,area);
	}
	
	fclose(fp);
	return 0;
}
