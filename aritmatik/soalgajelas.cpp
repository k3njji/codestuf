#include<stdio.h>

int main()
{
	int a, b, c, d, jwb1, jwb2, jwb3;
	char open1, plus, close1, times, open2, min, close2;
	
	for(int i=0; i<3; i++) {
		scanf("%c%d%c%d%c%c%c%d%c%d%c\n", &open1, &a, &plus, &b, &close1, &times, &open2, &c, &min, &d, &close2);
		getchar();
		if(i==0) jwb1=(a+b)*(c-d);
		else if(i==1) jwb2=(a+b)*(c-d);
		else jwb3=(a+b)*(c-d);
	}
	
	printf("%d %d %d\n", jwb1, jwb2, jwb3);
	
	return 0;
}
