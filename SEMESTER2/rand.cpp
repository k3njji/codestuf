#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main()
{
//	int i=0;
	while(1){
	srand(time(NULL));
	// range dari 100 ke 50
	int n = (rand() % (100-50))+50;
	printf("%d ", n);
//	i++;
	}
	
	
	return 0;
}
