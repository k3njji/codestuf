#include <stdio.h>

int count = 0;

int banjir(char x[105][105], int y, int z){
	x[y][z] = '#';
	
	if(x[y+1][z] == '.'){
		count++;
		banjir(x, y+1, z);
	}
	if(x[y-1][z] == '.'){
		count++;
		banjir(x, y-1, z);
	}
	if(x[y][z+1] == '.'){
		count++;
		banjir(x, y, z+1);
	}
	if(x[y][z-1] == '.'){
		count++;
		banjir(x, y, z-1);
	}
	return 0;
}



int main()
{
	int t;
	int a, b;
	
	scanf("%d", &t);
	
	for(int i = 0 ; i < t ; i++){
		count = 0;
		char sim[105][105] = {}; 
		int temp;
		int temp2;
		scanf("%d %d", &a, &b); getchar();
		
		for(int j = 0 ; j < a ; j++){
			for(int k = 0 ; k < b ; k++){
				scanf("%c", &sim[j][k]); 
			}
			getchar();
		}
		for(int j = 0 ; j < a ; j++){
			for(int k = 0 ; k < b ; k++){
				if(sim[j][k] == 'S'){
				temp = j;
				temp2 = k;	
				}
			}
		}
		printf("Case #%d: ", i+1);
		banjir(sim, temp, temp2);
		printf("%d\n", count);
	}
	
	
	return 0;
}
