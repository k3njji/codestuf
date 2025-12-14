#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#include<math.h>

const int max = 100;

struct Node{
	char ID[100];
	char name[100];
	char fill[100];
	double size;
	double price;
	Node *next;
} *table[max]={NULL};

Node *makeNode(char name[], char fill[], double size){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	strcpy(newNode->fill, fill);
	newNode->size = size;
	if(strcmp(fill, "Vanilla")==0){
		newNode->price = size*10000;
	}else if(strcmp(fill, "Chocolate")==0){
		newNode->price = size*15000;
	}else if(strcmp(fill, "Coffee")==0){
		newNode->price = size*20000;
	}
	int a = size;
	
	sprintf(newNode->ID, "%c%c%d%00d", name[0], fill[0], a, rand()%100);
	newNode->next = NULL;
	
	return newNode;
}

int hashing(char id[]){
	int count = 0;
	count = (id[2]-'0') + (id[2]-'0') + (id[2]-'0');
	
	return (count*5)%max;
}

void insert(char name[], char fill[], double size){
	Node *newNode = makeNode(name, fill, size);
	int key = hashing(newNode->ID);
	
	if(table[key]==NULL){
		table[key] = newNode;
		return;
	}else{
		Node *curr = table[key];
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = newNode;
		return;
	}
}

void push(){
	char name[100];
	char fill[100];
	double size;
	int vali=0;
	int len;
	
	printf("Enter Waffle Name [start with capital and contains 3-10 character]: ");
	scanf("%[^\n]", name); getchar();
	
	if(name[0] >= 'A' && name[0] < 'Z') vali = 1;
	len = strlen(name);
	
	while(vali == 0 || (len < 3 || len > 20)){
	printf("Enter Waffle Name [start with capital and contains 3-10 character]: ");
	scanf("%[^\n]", name); getchar();
	if(name[0] >= 'A' && name[0] < 'Z') vali = 1;
	len = strlen(name);
	}
	
	vali = 0;
	do{
		printf("Enter Waffle Filling [Vanilla|Chocolate|Coffee] (Case Sensitive): ");
		scanf("%s", fill); getchar();
	}while((strcmp(fill, "Vanilla")!=0) && (strcmp(fill, "Chocolate")!=0) && (strcmp(fill, "Coffee")!=0));
	
	do{
		printf("Enter Waffle Size [1.0 - 5.0]: ");
		scanf("%lf", &size); getchar();
	}while(size < 1.0 || size > 5.0);
	
	insert(name, fill, size);	
}
	
void del(){
	char id[100];
	int cek = 0;
	do{
	printf("Input Waffle ID to be deleted (must be exists and case sensitive): ");
	scanf("%s", id); getchar();
	for(int i=0; i<max; i++){
		Node *curr = table[i];
		while(curr){
			if(strcmp(curr->ID, id)==0) cek = 1;
			curr = curr->next;
		}
	}
	}while(cek==0);
	
	char check;
	do{
	printf("Are you sure you want to Delete this order? [Y/N] (Case Sensitive): ");
	scanf("%c", &check); getchar();
	}while(check!='Y' && check!='N');
	
	if(check=='Y'){
	int key = hashing(id);
		if(strcmp(table[key]->ID, id)==0){
			Node *temp = table[key]->next;
			table[key]->next = NULL;
			free(table[key]);
			table[key] = temp;
		}else{
			Node *curr = table[key];
			while(curr){
				if(strcmp(curr->next->ID, id)==0){
					Node *temp = curr->next->next;
					free(curr->next);
					curr->next = temp;
				}
				curr = curr->next;
			}
		}
		printf("Deleted\n");
	}
}

void popAll(){
	for(int i=0; i<max; i++){
		while(table[i]){
		Node *temp = table[i]->next;
		table[i]=NULL;
		free(table[i]);
		table[i]=temp;
		}
	}
}
	
int view(){
	puts("WAFFLE ID || WAFFLE NAME || WAFFLE FILLING || SIZE || PRICE");
	int vali = 0;
	for(int i=0; i<max; i++){
		Node *curr = table[i];
		while(curr){
			printf("%s %s %s %0.2lf %0.2lf\n", curr->ID, curr->name, curr->fill, curr->size, curr->price);
			vali=1;
			curr = curr->next;
		}
	}
	return vali;
}

void menu(){
	puts("Rolling Waffle");
	puts("1. Insert Waffle");
	puts("2. View Waffle");
	puts("3. Delete Waffle");
	puts("4. Exit");
	puts("Choose Menu [1-4]: ");
}

int main()
{
	srand(time(NULL));
	
	while(1){
		system("cls");
		menu();
		int choice;
		scanf("%d", &choice); getchar();
		if(choice==1){
			push();
		}else if(choice==2){
			int key = view();
			if(!key) puts("There is No Data");
		}else if(choice==3){
			int key = view();
			if(!key){
				puts("There is no Data");
				break;
			}else{
				del();
			}
		}else if(choice==4){
			printf("Thank You!\n");
			printf("Press Any to Exit"); getchar();
			break;
		}else if(choice==5){
			popAll();
		}
		printf("Press Enter to cont: "); getchar();
	}
	return 0;
}
