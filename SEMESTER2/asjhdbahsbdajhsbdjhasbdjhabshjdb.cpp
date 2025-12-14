#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[50];
	Node *next;
} *head = NULL, *tail = NULL;

Node *makeNode(char name[]){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->next = NULL;
	return newNode;
}

void push(char name[]){
	Node *newNode = makeNode(name);
	if(!head){
		head = tail = newNode;
	}else if(strcmp(head->name, name) > 0){
		newNode->next = head;
		head = newNode;
	}else if(strcmp(tail->name, name) < 0){
		tail->next = newNode;
		tail = newNode;
	}
	else{
		Node *curr = head;
		while(curr){
			if(strcmp(curr->next->name, name) > 0){
				newNode->next = curr->next;
				curr->next = newNode;
				return;
			}
			curr = curr->next;
		}
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

void pop(char name[]){
	if(strcmp(head->name, name)==0){
		popHead();
	}else if(strcmp(tail->name, name)==0){
		popTail();
	}else{
		Node *curr = head;
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

void print(){
	Node *curr = head;
	while(curr){
		printf("%s -> ", curr->name);
		curr = curr->next;
	}
	puts("NULL");
}

int main()
{
	push("darlyn");
	push("alvino");
	push("felis");
	push("ben");
	print();
	
	pop("darlyn");
	pop("felis");
	pop("alvino");
	print();
	
	
	return 0;
}
