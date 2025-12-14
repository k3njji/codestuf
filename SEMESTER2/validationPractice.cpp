#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void menu(){
	puts("MINISO");
	puts("1. Insert Product");
	puts("2. Delete Product");
	puts("3. Exit");
}

void cls(){
	for(int i=0; i<25; i++){
		puts("");
	}
}

void insert(){
	char kata[25];
	do{
		printf("input kata: ");
		scanf("%s", kata); getchar();
	}while(strlen(kata) > 6);
	
	int price;
	do{
		printf("input harga: ");
		scanf("%d", &price);
	}while(price>150000 || price < 1);
	
	char gend[5];
	do{
		printf("input Mr/Mrs: ");
		scanf("%s", gend); getchar();
	}while((strcmp(gend, "Mr")!=0) && (strcmp(gend, "Mrs")!=0));
}

int main()
{	
	int choice;
	do{
		menu();
		printf("Input Choices: ");
		scanf("%d", &choice);
//		system("cls");
//		cls();
		switch(choice){
			case 1:
				insert();
				break;
			case 2:
//				pop();
				break;
		}
		
	}while(choice!=3);
	
	return 0;
}
