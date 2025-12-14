#include<stdio.h>

int main()
{
	FILE *fptr = fopen("data.csv", "r");
	struct Movie{
		char name[100];
		char year[100];
		int rating;
	};
	Movie movie[100];
	int lineCounter=0;
	while(!feof(fptr)){
		char temp[100];
		fscanf(fptr, "%[^;];%[^;];%d\n", &movie[lineCounter].name, &movie[lineCounter].year, &movie[lineCounter].rating);
		lineCounter++;
	}
	
	for(int i=0; i<lineCounter; i++){
		printf("%s\n", movie[i].name);
		printf("%s\n", movie[i].year);
		printf("%d\n", movie[i].rating);
	}
	fclose(fptr);

	return 0;
}
