#include<stdio.h>
#include<string.h>

struct ranking
{
	char name[1000];
	int rank;
};

int main()
{
	int test;
	scanf("%d", &test);
	getchar();
	
	for(int i=1; i<=test; i++){
		int x;
		scanf("%d", &x);
		getchar();
		
		struct ranking d[x];
			for(int j=0; j<x; j++){
				scanf("%[^#]#%d", &d[j].name, &d[j].rank);
				getchar();
			}
			
			for(int j=0; j<x-1; j++){
				for(int k=0; k<x-j-1; k++){
					if(d[k].rank < d[k+1].rank){
						struct ranking temp = d[k];
						d[k]=d[k+1];
						d[k+1]=temp;
					}
					if(d[k].rank == d[k+1].rank){
					if(strcmp(d[k].name, d[k+1].name)>0){
						struct ranking temp = d[k];
						d[k]=d[k+1];
						d[k+1]=temp;
					}
					}
				}
			}
//			for(int j=0; j<x; j++){
//				printf("%s %d", d[j].name, d[j].rank);
//			}
			char input[1000];
			scanf("%[^\n]s", &input);
			for(int j=0; j<x; j++){
				if(strcmp(input, d[j].name)==0){
					printf("Case #%d: %d\n", i, j+1);
					break;
				}
			}
	}
	return 0;
}

//2
//3
//Jojo#40
//Lili#80
//Bibi#90
//Lili
//3
//Jojo#100
//Lili#80
//Bibi#90
//Lili
