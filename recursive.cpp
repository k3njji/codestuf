#include<stdio.h>
#include<string.h>


int addition(int a, int b){ //ex. a=3, b=4
	return a+b; //a+b = 7, return 7
}

void modifyValue(int a){ //passing by value
	
}


void modifyRef(int *a){ //pass by reference
// changing the value of the source address
// you cannot change the address
	int temp=99;
	printf("address a: %p\n", a);
	*a+=5; //changing the value of source address by an addition of 5
}

void print(int counter, int n){
	if(counter == n){
		return;
	}
	printf("%d\n", counter);
	print(counter+1, n);
	printf("%d\n", counter);
}


int main()
{
	
	int a=9, b=3, toModify=55;
	int result=0;
	result = addition (a, b);
	printf("Result: %d\n", result);
	printf("a: %d | b: %d | toModify: %d\n", a, b, toModify);
	printf("address toModify: %p\n", &toModify);
	modifyRef(&toModify);
	printf("Addition: %d\n", toModify);
	
	print(0, 5);
	
	
	char name[100] = "Juan";
	char name2[100] = "Bob";
	//strcpy = stringcopy;
	//strcmp - stringcompare
	//strcmpi - stringcompare (case insensitive)
	printf("Length of Name: %d\n", strlen("Kenzie"));
	printf("name1: %s\n", name);
	printf("name2: %s\n", name2);
	
	printf("Compare Value: %d\n", strcmp("Bob", "Aob"));
	
	
	
	int num;
	char name3[100];
	
	scanf("%s", &name3); getchar();
	for(int i = 0; i<strlen(name3); i++){
		if(name3[i] >= '0' && name3[i]<='9'){
			printf("Evaluated Char: %c | ASCII: %d | ASCII '0': %d\n", name3[i], name3[i], '0');
			printf("Number: %d\n", name3[i]-'0');
		}
	}

	
	
	
	return 0;
}
