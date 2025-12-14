#include<stdio.h>

int main()
{
	//1
	int a;
	a = 20;
	
	int *ptr_a;
	ptr_a = &a;
	
	printf("value of a: %d\n", a);
	printf("addres of a: %d\n", &a);
	
	printf("value of ptr_a: %d\n", ptr_a);
	printf("value a through ptr_a: %d\n", *ptr_a);
	printf("address of ptr_a: %d", &ptr_a);
	
	*ptr_a = 10;
	printf("value of a: %d\n", a);
	//& -> get variable address
	//* -> get value of the variab;es through pointer
	return 0;
}

