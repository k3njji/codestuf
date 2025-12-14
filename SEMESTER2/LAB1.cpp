#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void printArray(int num[]){
	for(int i=0; i<5; i++){
		printf("%d ", num[i]);
	}
	puts("");
}

struct person{
	char name[1000];
	int age;
}person1, person2;

int main()
{
	/*
	Array is a storage to store dara where the data is homogenous
	create : data_type variable's_name[size]
	insert:
	1. declare it next to the array
	2. declare it via index
	
	int num[5] = {1, 2, 3, 4, 5};
	num[0] = 1;
	
	printf("%x\n", num);
	printArray(num);
	
	*(num+2)= 2;
	printArray(num);
	*/
	
	
//	Pointer
	int num1=10;
	int *ptr = &num1;
	*ptr = 5;
//
//	printf("the value of num1: %d\n", num1);
//	printf("the value of num1 pointed from ptr: %d\n", *ptr);	
//	printf("the address of num1: %x\n", &num1);
//	printf("the value of ptr %x\n", ptr);
//	printf("the address of ptr %x\n", &ptr);
//	puts("");
//	
//	int **ptr2 = &ptr;
//	**ptr2 = 7;
//	printf("the value of ptr2: %d\n", **ptr2);
//		printf("the address pointer by ptr2: %x\n", *ptr2);
//			printf("the address of ptr2: %x\n", ptr2);
//	puts("");
	
	int num2=3;
	*ptr=num2;
	printf("the value of num1: %d\n", num2);
	printf("the value of num1 pointed from ptr: %d\n", ptr);	
	printf("the address of num1: %x\n", &num2);
	printf("the value of ptr %x\n", ptr);
	printf("the address of ptr %x\n", &ptr);
	
	int *num = (int*)malloc(sizeof(int) * 5);
	//using pointer to insert value
	//we can use array like normal to insert 
	*num = 1;
	*(num+1) = 2;
	*(num+2) = 3;
	*(num+3) = 4;
	*(num+4) = 5;
	*(num+5) = 6;

//	num[6] = 3;
	printf("%d", *(num+5));
	
	
	struct person *person3;
	strcpy(person3->name, "Guido");
	person3->age=10;
	printf("%s %d", person3->name, person3->age);
	
//	person *person3;
//	person *ptr = &person3;
//	strcpy(*ptr.name, "Guido");
//	ptr->age = 10;
//	person3.age = 10;
//	printf("address of name : %d\n", &(person3.name));
//	printf("address of age : %d\n", &(person3.age));
//	printf("address of person3 : %d\n", &(person3));
//	printf("%s %d", ptr->name, ptr->age);



	
	
	
	
	return 0;
}
