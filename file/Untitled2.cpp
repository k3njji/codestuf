#include<stdio.h>

int main()
{
	FILE *fp;
	fp = fopen("testdata.in", "w");
	fputs("1\n", fp);
	fputs("20 3 5\n", fp);
	fputs("10110011110111111001\n", fp);
	fputs("1\n", fp);
	fputs("20 3 6\n", fp);
	fputs("10110011110111111001\n", fp);
	
	fclose(fp);
	
	return 0;
}
