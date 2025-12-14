#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>

const int max = 1007;

int count = 0;

struct Node{
	char book[55];
	char author[30];
	char ISBN[20];
	int page;
	char bookID[20];
	Node *next;
} *table[max]={NULL};

Node *makeNode(char book[], char author[], char ISBN[], int page){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->book, book);
	strcpy(newNode->author, author);
	strcpy(newNode->ISBN, ISBN);
	newNode->page = page;
	sprintf(newNode->bookID, "B0000%d-%s-%c%c", count++, ISBN, book[0], author[0]);
	printf("%s\n", newNode->bookID);
	
	return newNode;
}
void cls(){
	for(int i=0; i<20; i++){
		printf("\n");
	}
}

int hashing(char word[]){
	int hash = 0;
	for(int i=0; i<strlen(word); i++){
		hash+=word[i];
	}
	return hash % max;
}

void insert(char book[], char author[], char ISBN[], int page){
	Node *newNode = makeNode(book, author, ISBN, page);
	int key = hashing(newNode->bookID);
	
	if(table[key]==NULL){
		table[key] = newNode;
		return;
	}else{
		Node *curr = table[key];
		while(curr->next!=NULL){
			curr = curr->next;
			printf("1");
		}
		curr->next = newNode;
	}
}

void view(){
	for(int i=0; i<max; i++){
		Node *temp = table[i];
		while(temp){
			printf("%s %s %s %s %d\n", temp->bookID, temp->book, temp->author, temp->ISBN, temp->page);
			temp = temp->next;
		}
	}
}

void del(){
	char book[100];
	printf("Input Book ID to delete: ");
	scanf("%s", book); getchar();
	
	int key = hashing(book);
	
	if(strcmp(table[key]->bookID, book)==0){
		printf("%s %s %s %s %d\n", table[key]->bookID, table[key]->book, table[key]->author, table[key]->ISBN, table[key]->page);		
		Node *temp = table[key]->next;
		free(table[key]);
		table[key] = temp;
		return;
	}else{
		Node *curr = table[key];
		while(curr){
			if(strcmp(curr->next->bookID, book)==0){
				Node *temp = curr->next->next;
				free(curr->next);
				curr->next = temp;
				return;
			}
			curr = curr->next;
		}
	}
	puts("Book Not Found");
}

void menu(){
	puts("Bluejack Library");
	puts("=================");
	puts("1. View Book");
	puts("2. Insert Book");
	puts("3. Remove Book");
	puts("4. Exit");
	printf(">>");
}

int unique(char book[]){
	for(int i=0; i<max ;i++){
		Node *curr = table[i];
		while(curr){
			if(strcmp(curr->book, book)==0){
				return 1;
			}
			curr = curr->next;
		}
	}
	return 0;
}

void push(){
	char book[55];
	char author[30];
	char ISBN[30];
	int page;
	
	int len;
	int check;
	int validate=0;
	do{
		printf("Input Book Title (5-50 characters): ");
		scanf("%[^\n]", &book); getchar();
		len = strlen(book);
		check = unique(book);
		printf("%d\n", check);
	}while(check == 1 || (len<5 || len>50));
	
	do{
		printf("Input Book Author (Include Mr. or Mrs.): ");
		scanf("%[^\n]", &author); getchar();
		if(author[0]=='M' && author[1]=='r' && author[2]=='.'){
			validate = 1;
		}
		if(author[0]=='M' && author[1]=='r' && author[2]=='s'&& author[3]=='.'){
			validate = 1;
		}
		len = strlen(author);
	}while(validate == 0 || (len<3 || len>25));
	
	int vali = 0;
	int vali2 = 0;
	do{
		int count=0;
		printf("Input ISBN (10-13 digits): ");
		scanf("%s", &ISBN); getchar();
		len = strlen(ISBN);
		for(int i=0; i<len; i++){
			if(isdigit(ISBN[i])){
				count++;
			}
		}
		if(count==len) vali=1;
		else vali = 0;
		
		if(count>=10 && count<=13){
			vali2=1;
		}
	}while(vali == 0 || vali2 == 0);
	
	do{
		printf("Input Page Number (Min 16): ");
		scanf("%d", &page);
	}while(page<16);
	
	insert(book, author, ISBN, page);
}

int main()
{
	srand(time(NULL));
	while(1){
		cls();
		int choice;
		menu();
		printf("Type the number: ");
		scanf("%d", &choice); getchar();
		if(choice == 2){
			push();
		}else if(choice == 1){
			view();
		}else if(choice == 3){
			del();
		}
		printf("press ent to cont: "); getchar();
	}
	return 0;
}
