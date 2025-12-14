#include<stdio.h>
const int x = 3939;

FILE *fp;

struct malay{
	char loc1[50];
	char loc2[50];
	int price;
	int room;
	int bath;
	int car;
	char type[50];
	int area;
	char furn[50];
}data[x];

int main()
{
	fp = fopen("file.csv", "r");
	char a [500];
	fscanf(fp, "%[^\n]", &a);
	
	int i;
	for(i=0; i<50; i++){
		fscanf(fp, " %[^;];%[^;];%d;%d;%d;%d;%[^;];%d;%[^\n]", &data[i].loc1, &data[i].loc2, &data[i].price, &data[i].room, &data[i].bath, &data[i].car, &data[i].type, &data[i].area, &data[i].furn);
		printf("%d\n", i);
	}
	
	return 0;
}
