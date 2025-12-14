#include<stdio.h>

int main(){
	int x,y;
	scanf("%d", &y);
	for(x=0;x<y;x++){
	
	int j,k;
	scanf("%d %d", &j, &k);
	int l[j];
	for(int a=0; a<j;a++){
		scanf("%d", &l[a]);
	}
	for(int a=0;a<j;a++){
			if(l[0]>l[a]){
				l[0]=l[a];
			}
	
	} 
	printf("Case #%d: %d\n", x+1, k/l[0]);
	


	}
		return 0;
}
