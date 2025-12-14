#include<stdio.h>
int main()
{
	
	char d[10] = "Daging";
	char s[10] = "Sayur";
	char t[10] = "Telur";
	
	int x, y, z;
	scanf("%d %d %d", &x, &y, &z);
	
	if(x>y&&y>z){
		printf("%s\n", d);
		printf("%s\n", s);
		printf("%s\n", t);
	}if(x<y&&y<z){
		printf("%s\n", t);
		printf("%s\n", s);
		printf("%s\n", d);
	}else if(x<y&&y>z&&x>z){
		printf("%s\n", s);
		printf("%s\n", d);
		printf("%s\n", t);
	}else if(x<y&&y>z&&x<z){
		printf("%s\n", s);
		printf("%s\n", t);
		printf("%s\n", d);
	}else if(x>y&&y<z&&x>z){
		printf("%s\n", d);
		printf("%s\n", t);
		printf("%s\n", s);	
	}else{
		printf("%s\n", t);
		printf("%s\n", d);
		printf("%s\n", s);
	}
	return 0;
}
