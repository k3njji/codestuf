#include<stdio.h>

struct group{
	
	char name[100];
	char gender[100];
	int score;
};

int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "w");
//	struct group doge [5];
//	int x;
////	fscanf(fp, "%d\n", &x);
////	struct group doge [5];
//	x=0;
//	
//	while(!feof(fp)){
//		fscanf(fp, "%[^#]#%[^#]#%d\n", &doge[x].name, &doge[x].gender, &doge[x].score);
//		x++;
//	}
//	for(int i=0; i<x; i++){
//	printf("%s %s %d\n", doge[i].name, doge[i].gender, doge[i].score);
//}

fprintf(fp, "\nmichael leung#yakuza#85");
	
	
	return 0;
}
