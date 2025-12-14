#include<stdio.h>
#include<stdlib.h>

/*
	pointers
	& -> the address
	* -> 
	
	array is part of pointers
	 example
	 int people [25]
	 printf("%d", *people)
	 this will print prople[0]
	 
	 printf("%d", *people+1)
	 this will print prople[1]
	 
	 ex2:
	 we have NIM with 10 char
	 the array vaue should be 11
	 char NIM[11]
	 because the last array need to be able to scan \n
	 
	 
	 soal: how to do swap with temporary
	 
	 
	 
	 
*/

int main()
{
	int  *px = (int *) malloc(sizeof(int));
char *pc = (char *) malloc(sizeof(char));
*px = 205;
*pc = 'a';
printf( "%d %c\n", *px, *pc );
free(px);
free(pc);

	
	return 0;
}
