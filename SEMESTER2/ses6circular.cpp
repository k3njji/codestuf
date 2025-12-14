#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int val;
	Node *next;
} *front=NULL, *rear=NULL;

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void push(int val){
	Node* newNode = makeNode(val);
	if(!front){
		front = rear = newNode;
		rear->next = front;
	}else{
		rear->next = newNode;
		rear = newNode;
		rear->next = front;
	}
}

void pop() {
	Node *temp = front;
    if(!front){
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else{
        front = front->next;
        rear->next = front;
    }
    free(temp);
}

void empty(){
	puts("=======================");
	puts("The Queue is Empty");
	puts("=======================");
}

void print(){
	if(!front){
		empty();
		return;
	}
	puts("=======================");
	Node *curr = front;
	while(curr != rear){
		printf("%d -> ", curr->val);
		curr=curr->next;
	}
	printf("%d\n", curr->val);
	printf("Front: %d\n", front->val);
	printf("Rear: %d\n", rear->val);
	puts("=======================");
}

void circular(){
	if(!front){
		empty();
		return;
	}
	puts("=======================");
	Node *curr = front;
	int count = 0;
	while(count != 2){
		if(curr->next == rear){
			count++;
		}
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	printf("%d\n", curr->val);
	puts("=======================");
}

int main()
{
	puts("CIRCULAR QUEUE IN CIRCULAR LINKED LIST");
	char word[100];
	while(1){
		puts("Type \"En\" to Enqueue");
		puts("Type \"De\" to Dequeue");
		puts("Type \"Circular\" to Print the Circular List 2 Times");
		puts("Type \"Exit\" to Terminate the Program");
		puts("Case Sensitive");
		scanf("%s", word);
		if(strcmp(word, "En")==0){	
			int val;
			scanf("%d", &val);
			push(val);
			print();
	}else if(strcmp(word, "De")==0){
		pop();
		print();
	}else if(strcmp(word, "Exit")==0){
		printf("Program Terminated");
		break;
	}else if(strcmp(word,"Circular")==0){
		circular();
	}
}
	return 0;	
}
