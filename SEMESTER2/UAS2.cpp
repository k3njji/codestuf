#include<stdio.h>
#include<string.h>

struct data{
	char name[509];
	int defen;
	int power;
	char type[10];
};

struct data data[1000];

void print(int count){
	for(int i=0; i<count; i++){
		printf("%s\n", data[i].name);
	}
}

int main()
{
	int count = 0;
	printf("Insert The Amount of Data you want to input: ");
	scanf("%d", &count); getchar();
	
	for(int i=0; i<count; i++){
		printf("Insert name: ");
		scanf("%[^\n]", data[i].name); getchar();
		printf("Insert Defense: ");
		scanf("%d", &data[i].defen); getchar();
		printf("Insert Power: ");
		scanf("%d", &data[i].power); getchar();
		printf("Insert Type: ");
		scanf("%[^\n]", &data[i].type); getchar();
	}
	
	int choice;
	while(true){
		menu();
		
		if()
	}
	
	
	
	return 0;
}
