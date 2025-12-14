#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct menu{
	char code[100];
	char name[100];
	int price;
	menu *next, *prev;
} *menuHead=NULL, *menuTail=NULL;

struct buyer{
	char name[100];
	char code[100];
	int qty;
	long long int price;
	int total;
	buyer *next, *prev;
} *buyerHead=NULL, *buyerTail=NULL;

menu* createMenu(char code[], char name[], int price){
	menu *newNode = (menu*)malloc(sizeof(menu));
	strcpy(newNode->code, code);
	strcpy(newNode->name, name);
	newNode->price = price;
	newNode->next = newNode->prev = NULL;
	
	return newNode;
}

buyer* createBuyer(char code[], char name[], int price, int qty){
	buyer *newNode = (buyer*)malloc(sizeof(buyer));
	strcpy(newNode->code, code);
	strcpy(newNode->name, name);
	newNode->price = price;
	newNode->qty = qty;
	newNode->next = newNode->prev = NULL;
	
	return newNode;
}

void pushMenu(char code[], char name[], int price){
	menu* newNode = createMenu(code, name, price);
	
	if(!menuHead){
		menuHead = menuTail = newNode;
	}else{
		newNode->prev = menuTail;
		menuTail->next = newNode;
		menuTail = newNode;
	}
}

int check(char code[]){
	menu *curr = menuHead;
	while(curr){
		if(strcmp(curr->code, code)==0){
			return 1;
		}
		curr = curr->next;
	}
	return 0;
}

int checker(char code[]){
	buyer *curr = buyerHead;
	while(curr){
		if(strcmp(curr->code, code)==0){
			return 1;
		}
	}
	return 0;
}

void add(char code[], int qty){
	buyer *curr = buyerHead;
	while(curr){
		if(strcmp(curr->code, code)==0){
			curr->qty = curr->qty + (qty);
			return;
		}
		curr = curr->next;
	}
}

void popHead(){
	if(!buyerHead){
		return;
	}else if(buyerHead == buyerTail){
		free(buyerHead);
		buyerHead = buyerTail = NULL;
	}else{
		buyer *temp = buyerHead->next;
		temp->prev = NULL;
		free(buyerHead);
		buyerHead = temp;
	}
}

void popTail(){
	if(!buyerHead){
		return;
	}else if(buyerHead == buyerTail){
		free(buyerHead);
		buyerHead = buyerTail = NULL;
	}else{
		buyer *temp = buyerTail->prev;
		temp->next = NULL;
		free(buyerTail);
		buyerTail = temp;
	}
}

void popAll(){
	while(buyerHead){
		popHead();
	}
}

void pop(char code[]){
	if(!buyerHead){
		return;
	}else if(strcmp(buyerHead->code, code)==0){
		popHead();
	}else if(strcmp(buyerTail->code, code)==0){
		popTail();
	}else{
		buyer *curr = buyerHead;
		while(curr){
			if(strcmp(curr->code, code)==0){
				buyer *temp = curr->next;
				temp->prev = curr->prev;
				free(curr);
				curr->prev->next = temp;
				return;
			}
			curr = curr->next;
		}
	}
}

void update(){
	char code[100];
	int qty;
	printf("Please Input The Code Items That You Want to Update: ");
	scanf("%s", code); getchar();
	printf("Please Input The Updated Quantity: ");
	scanf("%d", &qty); getchar();
	if(qty == 0){
		pop(code);
	}else{
		buyer *curr = buyerHead;
		while(curr){
			if(strcmp(curr->code, code)==0){
				curr->qty = qty;
			}
			curr= curr->next;
		}
	}
}

void pushBuyer(char code[], int qty){
	int cek=0;
	buyer *curr = buyerHead;
	while(curr){
		if(strcmp(curr->code, code)==0){
			cek = 1;
		}
		curr = curr->next;
	}
	
	if(cek==1){
		add(code, qty);
	}else{
	menu* curr = menuHead;
	while(curr){
		if(strcmp(curr->code, code)==0){
			break;
		}
		curr = curr->next;
	}
	
	buyer *newNode = createBuyer(curr->code, curr->name, curr->price, qty);
	puts("1");
	if(!buyerHead){
		buyerHead = buyerTail = newNode;
	}else{
		newNode->prev = buyerTail;
		buyerTail->next = newNode;
		buyerTail = newNode;
	}
}
}

void insert(){
	char code[100];
	int cek=1;
	do{
	if(cek == 0) puts("Items does not exist");
	printf("Please Input The Items Code: ");
	scanf("%s", code); getchar();
	cek = check(code);
	}while(cek==0);
	
	int qty;
	printf("Please Input The Quantity of the Items: ");
	scanf("%d", &qty); getchar();
	
	pushBuyer(code, qty);
}

void viewMenu(){
	menu *curr = menuHead;
	puts("MENU: ");
	printf("||%-10s||%-10s||%-10s||\n", "Code", "Name", "Price");
	while(curr){
		printf("||%-10s||%-10s||%-10lld||\n", curr->code, curr->name, curr->price);
		curr = curr->next;
	}
}

void viewBuyer(){
	buyer *curr = buyerHead;
	puts("BILL: ");
	printf("||%-10s||%-10s||%-10s||%-10s||%-10s||\n", "Code", "Name", "Price", "Qty", "Total");
	while(curr){
		printf("||%-10s||%-10s||%-10d||%-10d||%-10lld||\n", curr->code, curr->name, curr->price, curr->qty, curr->qty*curr->price);
		curr = curr->next;
	}
}

void menu(){
	puts("Type the Numbers");
	puts("1. Buy");
	puts("2. Update");
	puts("3. Exit");
}

int main()
{
	pushMenu("01", "Apple", 15000);
	pushMenu("02", "Orange", 15000);
	pushMenu("03", "Grape", 6000);
	pushMenu("04", "Peach", 20000);
	pushMenu("05", "Banana", 8000);
	
	while(1){
		system("cls");
		viewMenu();
		viewBuyer();
		menu();
		int choice;
		printf("Input The Number: ");
		scanf("%d", &choice);
		if(choice == 1){
			insert();
		}else if(choice == 2){
			update();
		}else if(choice == 3){
			popAll();
			break;
		}
	}
	return 0;
}
