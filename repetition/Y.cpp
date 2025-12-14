#include<stdio.h>
int main()
{
	
	int x;
	scanf("%d", &x);
	for(int i=1; i<=x; i++){
		int pan, leb;
		scanf("%d %d", &pan, &leb);
		printf("Case #%d:\n", i);
		for(int j=1; j<=pan; j++){
			for(int k=1; k<=leb; k++){
				if(j==1 || j==pan || k==1 || k==leb){
					printf("#");
				}else{
					printf(" ");
				}
			}
			printf("\n");
		}
	}
	
	return 0;
}
