#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int val;
	Node *next;
}*head=NULL, *tail=NULL;

Node *makeNode(int value){
	Node* newNode = (Node*)malloc(sizeof(Node*));
	newNode->val = value;
	newNode->next = NULL;
	return newNode;
}

void pushHead(int value){
	Node *newNode = makeNode(value);
	if(!head){
		head = tail = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int value){
	Node *newNode = makeNode(value);
	if(!head){
		head = tail = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
}

void pushMid(int value){
//	printf("a\n");
	if(!head || head->val >= value){
		pushHead(value);
	}else if(tail->val <= value){
		pushTail(value);
	}else{
		Node* newNode = makeNode(value);
		Node* curr = head;
		while(curr->next!=NULL){
			if(curr->next->val >= value){
				newNode->next = curr->next;
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
		head = tail = NULL;
		free(head);
	}else{
		Node* temp = head->next;
		free(head);
		head = temp;
	}
}

void popTail(){
	if(!head){
		return;
	}else if(head == tail){
			free(tail);
		head = tail = NULL;
		
	}else{
		Node *curr = head;
		while(curr->next!=tail){
			curr = curr->next;
		}
		curr->next = NULL;
		free(tail);
		tail = curr;
	}
}


void popMid(int value){
	if(!head){
		return;
	}else if(value == head->val){
		popHead();
	}else if(value == tail->val){
		popTail();
	}else{
		Node *curr = head;
		while(curr->next !=NULL){
			if(curr->next->val == value){
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
	while(curr !=NULL){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	printf("NULL\n");
	
	printf("HEAD : %d\n", head->val);
	printf("TAIL : %d\n", tail->val);
}

int main()
{
	
	pushMid(8);
	pushMid(3);
	pushMid(1);
	pushMid(10);
	pushMid(6);
	pushMid(4);
	pushHead(100);
	pushTail(90);
	print();
	popHead();
	print();
	popTail();
	print();
	popMid(10);
	print();

	return 0;
}
