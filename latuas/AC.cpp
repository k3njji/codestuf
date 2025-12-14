#include<stdio.h>
#include<stdlib.h>

int main()
{
	int x;
	scanf("%d", &x); getchar();
	for(int i=1; i<=x; i++){
	
	char numb[1000000];
	scanf("%s", numb); getchar();
	
	int num = atoi(numb);
	printf("Case #%d: ", i);
	if(num%6==0){
		printf("YES\n");
	}else{
		printf("NO\n");
	}
}
	return 0;
}
