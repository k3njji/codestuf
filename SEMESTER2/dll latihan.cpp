#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[4][50];
	char title[50];
	int year;
	int count;
	Node *next;
} *head = NULL, *tail = NULL;

Node *makeNode(char name[], char title[], int year, int count){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->count = count;
	strcpy(newNode->title, title);
	newNode->year = year;
	newNode->next = NULL;
	
    char* token;
    char* rest = name;
 	int itung = 0;
    while ((token = strtok_r(rest, "#", &rest))){
        strcpy(newNode->name[itung], token);
        itung++;
    }
    
    return newNode;
}

void menu(){
	puts("1. Insert");
	puts("2. View");
	puts("3. Deete");
	puts("4. Update");
	puts("5. Exit");
	printf("Type the number: ");
}

void pushHead(char name[], char title[], int year, int count){
	Node *newNode = makeNode(name, title, year, count);
	if(head == NULL){
		head = tail = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(char name[], char title[], int year, int count){
	Node *newNode = makeNode(name, title, year, count);
	if(!head){
		head = tail = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
}

void insert(char name[], char title[], int year, int count){
	if(!head || head->year > year){
		pushHead(name, title, year, count);
	}else if(tail->year < year){
		pushTail(name, title, year, count);
	}else{
		Node *newNode = makeNode(name, title, year, count);
		Node *curr = head;
		while(curr->next){
			if(curr->next->year > year){
				newNode->next = curr->next;
				curr->next = newNode;
				return;
			}
			curr = curr->next;
		}
	}
}

void push(){
	char name[500]={NULL};
	char title[50]={NULL};
	int year;
	int count = 0;
	do{
	printf("Input Names: ");
	scanf("%[^\n]", &name); getchar();
	count = 1;
	for(int i=0; i<strlen(name); i++){
		if(name[i]=='#'){
			count++;
		}
	}
	} while(count > 3);
	printf("Input Title: ");
	scanf("%[^\n]", &title); getchar();
	printf("Input Year: ");
	scanf("%d", &year); getchar();
	
	insert(name, title, year, count);
}

void view(){
	Node *curr = head;
	while(curr){
		printf("Names: ");
		for(int i=0; i<curr->count; i++){
			printf("%s ", curr->name[i]);
		}
		puts("");
		printf("Title: %s ", curr->title);
		printf("Year: %d ", curr->year);
		puts(" ");
		curr = curr->next;
	}
}

void popHead(){
	if(!head) return;
	if(head == tail){
		free(head);
		head = tail = NULL;
	}else{
		Node *temp = head->next;
		free(head);
		head = temp;
	}
}

void popTail(){
	if(!head) return;
	if(head == tail){
		free(head);
		head = tail = NULL;
	}else{
		Node *curr = head;
		while(curr->next->next!=NULL){
			curr = curr->next;
		}
		free(curr->next);
		curr->next = NULL;
	}
}

void popAfter(int year){
	puts("2");
	struct Node *curr = tail;
	
	while(curr != NULL){
		if(curr->year != year){
			popTail();	
		}
		else{
			break;
		}
		curr = curr->next;
	}
}

void popBefore(int year){
	puts("1");
	struct Node *curr = head;
	
	while(curr != NULL){
		if(curr->year != year){
			popHead();	
		}
		else{
			break;
		}
		curr = curr->next;
	}
}

int searching(int year){
	if(head == NULL){
		return 0;
	}
	else{
		struct Node *curr = head;
		
		while(curr != NULL){
			if(year == curr->year){
				return 1;
			}
			curr = curr->next;
		}
	}
	
	return 0;
}

void pop(){
	int delYear;
	int validate = 0;
	
	do{
		printf("Input the year you would like to delete: ");
		scanf("%d", &delYear); getchar();	
		validate = searching(delYear);
		
		if(validate == 0){
			printf("The year you would like to delete doesn't exist\n");
		}
	} while(validate == 0);
	
	char vali[100];
	printf("Would you like to delete the book published before or after [before|after] [Case Sensitive]:\n");
	scanf("%s", vali); getchar();
	
	if(strcmp(vali, "before") == 0){
		popBefore(delYear);
	}
	else if(strcmp(vali, "after") == 0){
		popAfter(delYear);
	}
	
}

void update(){
	char name[50];
	printf("Insert the Title you want to search: ");
	scanf("%[^\n]", name); getchar();
	
	Node *curr = head;
	while(curr){
		if(strstr(curr->title, name)==0){
			printf("Insert the new Title");
			char title[50];
			scanf("%[^\n]", title); getchar;
			strcpy(curr->title, title);
			return;
		}
		curr = curr->next;
	}
}

int main()
{
	while(1){
		system("cls");
		int x;
		menu();
		scanf("%d", &x); getchar();
		if(x==1){
			push();
		}else if(x==2){
			view();
		}else if(x==3){
			pop();
		}else if(x==4){
			update();
		}else if(x==5){
			puts("Thank You!");
			return 0;
		}
		puts("press ent to cont"); getchar();
	}
	return 0;
}
