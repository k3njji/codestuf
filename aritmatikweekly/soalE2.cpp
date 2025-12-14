#include<stdio.h>

int main()
{
	char course1[10];
	char course2[10];
	char course3[10];
	char course4[10];
	char course5[10];
	
	int aa1, bb1, cc1, dd1;
	int aa2, bb2, cc2, dd2;
	int aa3, bb3, cc3, dd3;
	int aa4, bb4, cc4, dd4;
	int aa5, bb5, cc5, dd5;
	
	scanf("%s %d:%d-%d:%d\n", &course1, &aa1, &bb1, &cc1, &dd1);
	scanf("%s %d:%d-%d:%d\n", &course2, &aa2, &bb2, &cc2, &dd2);
	scanf("%s %d:%d-%d:%d\n", &course3, &aa3, &bb3, &cc3, &dd3);
	scanf("%s %d:%d-%d:%d\n", &course4, &aa4, &bb4, &cc4, &dd4);
	scanf("%s %d:%d-%d:%d", &course5, &aa5, &bb5, &cc5, &dd5);
	
	printf("%s %02d:%02d-%02d:%02d\n", course1, --aa1, bb1, --cc1, dd1);
	printf("%s %02d:%02d-%02d:%02d\n", course2, --aa2, bb2, --cc2, dd2);
	printf("%s %02d:%02d-%02d:%02d\n", course3, --aa3, bb3, --cc3, dd3);
	printf("%s %02d:%02d-%02d:%02d\n", course4, --aa4, bb4, --cc4, dd4);
	printf("%s %02d:%02d-%02d:%02d\n", course5, --aa5, bb5, --cc5, dd5);
	
	return 0;

}
