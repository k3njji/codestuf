#include<stdio.h>

int main()
{
	
	int x;
	scanf("%d", &x);
	
	for(int i=0; i<x; i++){
		int a, b, c, d, e, f;
		scanf("%d %d %d %d %d %d", &a, &b, &c, &d, &e, &f);
		printf("Case #%d: ", i+1);
			for(int j=0; j<a; j++){
				printf("a");
			}for(int k=0; k<b; k++){
				printf("s");
			}for(int l=0; l<c; l++){
				printf("h");
			}for(int m=0; m<d; m++){
				printf("i");
			}for(int n=0; n<e; n++){
				printf("a");
			}for(int o=0; o<f; o++){
				printf("p");
			}
		printf("\n");
	}
	
	return 0;
}
