#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

const int max = 10;

struct Node{
	char name[100];
	int value;
	Node *next;
} *table[max] = {NULL};

Node *createNode(int value, char name[]){
	Node* newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->value = value;
	newNode->next = NULL;
	
	return newNode;
}

int hashing(char name[]){
	int count = 0;
	for(int i=0; i<strlen(name); i++){
		count=+name[i];
	}
	return (count%max);
}

void push(int value, char name[]){
	Node *newNode = createNode(value, name);
	int key = hashing(name);
	
	if(table[key] == NULL){
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

void view(){
	for(int i=0; i<max; i++){
		Node *curr = table[i];
		while(curr){
			printf("%s %d\n", curr->name, curr->value);
			curr = curr->next;
		}
	}
}

void search(char name[]){
	int key = hashing(name);
	
	if(strcmp(table[key]->name, name)==0){
		puts("Found");
		return;
	}else{
		Node *curr = table[key];
		while(curr != NULL){
			if(strcmp(curr->next->name, name)==0){
				puts("Found");
				return;
			}
			curr = curr->next;
		}
		puts("Not Found");
	}

//	for(int i=0; i<max; i++){
//		Node *curr = table[i];
//		while(curr){
//			if(strcmp(curr->name, name)==0){
//				puts("Found");
//				return;
//			}
//			curr = curr->next;
//		}
//	}
//	
//	puts("Not Found");
}

void del(char name[]){
	int key = hashing(name);
	
	if(strcmp(name, table[key]->name)==0){
		Node *temp = table[key]->next;
		table[key]->next = NULL;
		free(table[key]);
		table[key] = temp;
	}else{
		Node *curr = table[key];
		while(curr){
			if(strcmp(curr->next->name, name)==0){
				Node *temp = curr->next->next;
				free(curr->next);
				curr->next = temp;
				return;
			}
			curr = curr->next;
		}
	}
}

int main()
{
	push(8, "Kenzie");
	push(4, "Remon");
	push(7, "Felis");
	push(2, "Bryan");
	view();
	del("Kenzie");
	view();
	search("Raymon");
	
	return 0;
}
