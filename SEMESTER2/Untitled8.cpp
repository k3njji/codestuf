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

void pop(){
	if(!front){
		return;
	}else{
		Node *temp = front->next;
		free(front);
		front = temp;
		rear->next = front;
	}
}

void print(){
	puts("=======================");
	Node *curr = front;
	while(curr != rear){
		printf("%d -> ", curr->val);
		curr=curr->next;
	}
	printf("%d\n", curr->val);
	printf("%d -> Front\n", front->val);
	printf("%d -> Rear\n", rear->val);
	puts("=======================");

}

void circular(){
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
		puts("Press Enqueue to Push");
		puts("Press Dequeue to Pop");
		puts("Circular to Print the Circular List 2 Times");
		puts("Press Exit to Terminate the Program");
		puts("Case Sensitive");
		scanf("%s", word);
		if(strcmp(word, "Enqueue")==0){	
			int val;
			scanf("%d", &val);
			push(val);
			print();
	}else if(strcmp(word, "Dequeue")==0){
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
