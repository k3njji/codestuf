#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// you don't allowed to change the structure of struct data
struct data {
	char name[101];
	unsigned int priority;
	struct data* next;
	struct data* prev;
};

struct data *head=0;
struct data *tail=0;

data *makeNode(char *name, unsigned int prio){
	data *newNode = (data*)malloc(sizeof(data));
	newNode->priority = prio;
	strcpy(newNode->name, name);
	newNode->next = newNode->prev = NULL;
	return newNode;
}

void pushHead(data *newNode){
	if(!head){
		head = tail = newNode;
	}else{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;	
	}
}

void pushTail(data *newNode){
	if(!head){
		head = tail = newNode;
	}else{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

void push(char *name, unsigned int priority) {
	/*
		please input your code here....
		note : you can add additional method if needed
	*/
	data *newNode = makeNode(name, priority);
	if(!head || head->priority > priority){
		pushHead(newNode);
	}else if(tail->priority <= priority){
		pushTail(newNode);
	}else{
		data *curr = head;
		while(curr){
			if(curr->next->priority > priority){
				curr->next->prev = newNode;
				newNode->next = curr->next;
				newNode->prev = curr;
				curr->next = newNode;
				return;
			}
			curr = curr->next;
		}
	}
}

void popAll() {
	/*
		please input your code here....
		note : you can add additional method if needed
	*/
	while(head){
		if(head == tail){
			free(head);
			head = tail = NULL;
		}else{
			data *temp = head->next;
			temp->prev = NULL;
			free(head);
			head = temp;
		}
	}
}

void menu() {
	printf("1. Add Queue\n");
	printf("2. View Queue\n");
	printf("3. Exit\n\n");
}

void addQueue() {
	char name[101];
	unsigned int priority, len;

	do {
		printf("\nInput name [1..100] : ");
		scanf("%s", name); fflush(stdin);
		len = strlen(name);
	}while(len<1 || len>100);
	
	do {
		printf("Input priority value [1..10] : ");
		scanf("%d", &priority); fflush(stdin);
	}while(priority<1 || priority>10);

	push(name, priority);
}

void viewQueue() {
	if(head == 0) {
		printf("\n\nQueue is empty...\n");	
	}
	else {
		int no = 1;
		printf("\nQueue List :\n");

		struct data* curr = head;
		while(curr != 0) {
			printf("%02d. %s\n", no++, curr->name);
			curr = curr->next;
		}

		printf("\n");
	}
}

int main() {
	int pil;
	do {
		menu();
		do {
			printf("Input your choice [1..3] : ");
			scanf("%d", &pil); fflush(stdin);
		}while(pil<1 || pil>3);
		
		switch(pil) {
			case 1:
				addQueue();
				break;
			case 2:
				viewQueue();
				break;
		}
		
		printf("\n");
	}while(pil!=3);
	
	popAll();
}
