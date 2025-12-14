#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int a = 10;
	int *ptr = &a;
	
	/*
	rumah bob di angka 10
	orang nanya ke kita dimana rumah bob
	jari kita nunjuk 10 {jari kita adalah pointer)
	*/
	struct Movie{
		char name[100];
		char year[100];
		int rating;
	};
	int n=2;
	Movie *movie = (Movie*)malloc(n*sizeof(Movie));
	
	for(int i=0; i<n; i++){
		scanf("%s", &(movie+i)->name); getchar;
		scanf("%s", &(movie+i)->year); getchar;
		scanf("%d", &(movie+i)->rating); getchar;
	}
	for(int i=0; i<n; i++){
		scanf("%s", (movie+i)->name);
		scanf("%s", (movie+i)->year);
		scanf("%d", (movie+i)->rating);
	}
//	strcpy((movie+2)->name, "Helo Kiti");
//	strcpy((movie+2)->year, "2007");
//	(movie+2)->rating = 5;
//	
//	printf("%s\n", (movie+2)->name);
//	printf("%s\n", (movie+2)->year);
//	printf("%d\n", (movie+2)->rating);
//	
	return 0;
}
