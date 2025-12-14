#include<stdio.h>

int main()
{
	
	int x, i, arr;
	scanf("%d", &x);
	int a, b, c;
	for(i=1; i<=x; i++){
		scanf("%d %d %d", &a, &b, &c);
		int save=0;
		for(int j=1; j<=a; j++){
			scanf("%d", &arr);
			if(b>=arr){
			if(arr>save){
				save=arr;
			}
			}
		}
		
		
		if(save>c && c<=b){
			printf("Case #%d: %d\n", i, save);
		}else{
			printf("Case #%d: %d\n", i, c);
		}
	}
	
	return 0;
}
