#include<stdio.h>

int main()
{
	int x;
	scanf("%d", &x);
	for(int i=1; i<=x; i++){
		
	int finish;
	scanf("%d", &finish);
	int start = 0;
	int jump = 1;
	int final =0;
	do{
		start = start+jump;
		jump=jump+1;
		final++;
	}while(start<finish);
	printf("Case #%d: %d\n", i, final);
}
	return 0;
}



