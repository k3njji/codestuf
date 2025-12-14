#include<stdio.h>
#include<string.h>
#include<stdlib.h>

const int max = 10;

struct Node{
	int val;
	char name[100];
	Node *next;
} *table[max] = {NULL};

Node* makeNode(int val, char name[]){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	strcpy(newNode->name, name);
	newNode->next = NULL;
	
	return newNode;
}

int function(char name[]){
	int count = 0;
	for(int i=0; i<strlen(name); i++){
		count+=name[i];
	}
	
	return count%max;
}

void push(int val, char name[]){
	Node *newNode = makeNode(val, name);
	int key = function(name);
	
	if(table[key]==NULL){
		table[key] = newNode;
	}else{
		Node *curr = table[key];
		while(curr->next!=NULL){
			curr = curr->next;
		}
		curr->next = newNode;
	}
}

void del(char name[]){
	int key = function(name);
	
	if(strcmp(table[key]->name, name)==0){
		Node *temp = table[key]->next;
		free(table[key]);
		table[key] = temp;
	}else{
		Node *curr = table[key];
		while(curr->next != NULL){
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

void search(int val){
	for(int i=0; i<max; i++){
		Node *curr = table[i];
		
		while(curr){
			if(curr->val == val){
				printf("Found %s", curr->name);
				return;
			}
			curr = curr->next;
		}
	}
	puts("Not Found");
}

void print(){
	for(int i=0; i<max; i++){
		Node *curr = table[i];
		printf("%d. ", i);
		while(curr){
			printf("%d %s -> ", curr->val, curr->name);
			curr = curr->next;
		}
		puts("NULL");
	}
}

int main()
{
	push(8, "Kenzie");
	push(7, "Felis");
	push(10, "Belle");
	push(11, "Taqi");
	push(20, "Alvino");
	push(21, "Darlyn");
	print();
	
	puts("");
	del("Belle");
	del("Kenzie");
	print();
	
	puts("");
	search(10);
	search(7);
	
	return 0;
}
