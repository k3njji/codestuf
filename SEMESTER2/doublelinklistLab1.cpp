#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char name[255];
	int age;
	Node *next, *prev;
} *head = NULL, *tail = NULL;

Node *makeNode(int age){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->age = age;
	newNode->next = newNode->prev = NULL;
}

void pushHead(int age){
	Node *newNode = makeNode(age);
	if(!head){
		head = tail = newNode;
	}else{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int age){
	Node *newNode = makeNode(age);
	if(!head){
		head = tail = newNode;
	}else{
		tail->next = newNode;
		newNode->prev = tail;
		tail = newNode;
	}
}

void pushMid(int age){
	if(!head || head->age >= age){
		pushHead(age);
	}else if(tail->age < age){
		pushTail(age);
	}else{
		Node *newNode = makeNode(age);
		Node *curr = head;
		while(curr->next !=NULL){
			if(curr->next->age >= age){
				Node *temp = curr->next;
				temp->prev = newNode;
				newNode->prev = curr;
				newNode->next = temp;
				curr->next = newNode;
				return;
			}
			curr = curr->next;
		}
	}
}

void popHead(){
	if(!head){
		return;
	}else if(head == tail){
		free(head);
		head = tail = NULL;
	}else{
		Node *temp = head->next;
		temp->prev = NULL;
		free(head);
		head = temp;
	}
}

void popTail(){
	if(!head){
		return;
	}else if(head == tail){
		free(head);
		head = tail = NULL;
	}else{
		Node *temp = tail->prev;
		tail->prev->next = NULL;
		tail->prev = NULL;
		free(tail);
		tail = temp;
	}
}

void popMid(int age){
	if(!head){
		return;
	}else if(head->age == age){
		popHead();
	}else if(tail->age == age){
		popTail();
	}else{
		Node *curr = head;
		while(curr){
			if(curr->age == age){
				Node *temp = curr->next;
				temp->prev = curr->prev;
				curr->prev->next = temp;
				free(curr);
				return;
			}
			curr = curr->next;
		}
	}
}

void print(){
	Node *curr = head;
	while(curr){
		printf("%d -> ", curr->age);
		curr = curr->next;
	}
	puts("NULL");
	
	curr = tail;
	while(curr){
		printf("%d -> ", curr->age);
		curr = curr->prev;
	}
	puts("NULL");
}

int main()
{
	pushMid(9);
	pushMid(8);
	pushMid(10);
	pushMid(3);
	pushMid(7);
	pushMid(1);
	print();
	puts("");
	puts("After PopHead");
	popHead();
	print();
	puts("");
	puts("After PopTail");
	popTail();
	print();
	puts("");
	puts("After PopMid (8)");
	popMid(8);
	print();
	puts("");
	popMid(1);
	print();
	puts("");

	return 0;
}
