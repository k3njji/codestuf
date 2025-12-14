#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	Node *next, *prev;
} *head = NULL, *tail = NULL;

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->prev = newNode->next = NULL;
	newNode->val = val;
	
	return newNode;
}

void pushHead(int val){
	Node *newNode = makeNode(val);
	if(!head){
		head = tail = newNode;
	}else{
		head->prev = newNode;
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int val){
	Node *newNode = makeNode(val);
	if(!head){
		head = tail = newNode;
	}else{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

void pushMid(int val){
	if(!head || head->val > val){
		pushHead(val);
	}else if(tail->val < val){
		pushTail(val);
	}else{
		Node *newNode = makeNode(val);
		Node *curr = head;
		while(curr->next!=NULL){
			if(curr->next->val > val){
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
		Node *curr = head;
		while(curr->next!=NULL){
			if(curr->next->val == val){
				Node *temp = curr->next->next;
				temp->prev = curr;
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
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	puts("NULL");
	
	Node *curr2 = tail;
	while(curr2){
		printf("%d -> ", curr2->val);
		curr2 = curr2->prev;
	}
	puts("NULL");
}

int main()
{
	pushMid(8);
	pushMid(9);
	pushMid(1);
	pushMid(10);
	pushMid(11);
	pushMid(5);
	print();
	
	popMid(1);
	popMid(11);
	popMid(8);
	print();
	
	return 0;
}
