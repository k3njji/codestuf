#include<stdio.h>

int main()
{
	
	int x;
	int n, a, b, c, d;
	scanf("%d", &x);
	
	for(int i=1; i<=x; i++){
		scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);
		int k=0;
		for(int y=1; y<=n; y++){
			if(y%a==0 || y%b==0 || y%c==0 || y%d==0){
			k+=1;	
			}
		}
		printf("Case #%d: %d\n", i, k);
	}
	
	return 0;
}
