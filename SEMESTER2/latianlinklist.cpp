#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int val;
	Node* next;
} *head=NULL, *tail=NULL;

Node* makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node*));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void pushHead(int val){
	Node* newNode = makeNode(val);
	if(head==NULL){
		head = tail = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int val){
	Node* newNode = makeNode(val);
	if(head==NULL){
		head = tail = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
}

void pushMid(int val){
	if(!head || head->val >= val){
		pushHead(val);
	}else if(tail->val < val){
		pushTail(val);
	}else{
		Node* newNode = makeNode(val);
		Node* curr = head;
		while(curr->next!=NULL){
			if(curr->next->val >= val){
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
	}else if(head==tail){
		free(head);
		head = tail = NULL;
	}else{
		Node *curr = head->next;
		free(head);
		head = curr;
	}
}

void popTail(){
	if(!head){
		return;
	}else if(head==tail){
		free(head);
		head = tail = NULL;
	}else{
		Node *temp = head;
		while(temp->next != tail){
			temp = temp->next;
		}
		temp->next = NULL;
		free(tail);
		tail = temp;
	}
}

void popMid(int val){
	if(!head){
		return;
	}else if(head->val == val){
		popHead();
	}else if(tail->val == val){
		popTail();
	}else{
		
	}
}

void print(){
	Node* curr = head;
	while(curr!=NULL){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	printf("NULL\n");
	
	printf("Head: %d\n", head->val);
	printf("Tail: %d\n", tail->val);
}

int main()
{
//	int x;
//	scanf("%d", &x);
//	for(int i=0; i<x; i++){
//		int a;
//		scanf("%d", &a);
//		pushMid(a);
//		print();
//	}	
//	for(int i=0; i<2; i++){
//		int a;
//		scanf("%d", &a);
//		popMid(a);
//		print();
//	}

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
