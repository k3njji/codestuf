#include<stdio.h>
#include<stdlib.h>
//link list

struct Node{
	int val;
	Node* next;
}*head = NULL, *tail = NULL;



Node* makeNode(int val){
	Node* newNode = (Node*)malloc(sizeof(Node*));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void pushHead(int val){
	Node* newNode = makeNode(val);
	if(head==NULL){
		head=newNode;
		tail=newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int val){
	Node *newNode = makeNode(val);
	if(head == NULL){
		head = newNode;
		tail = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
}

void pushMid(int val){
	if(head==NULL || val <= head->val){
		pushHead(val);
	}else if(val >= tail->val){
		pushTail(val);
	}else{
		Node* curr = head;
		Node* newNode = makeNode(val);
		while(curr->next != NULL){
			if(curr->next->val >= val){
			newNode->next = curr->next;
			curr->next = newNode;
			return;
			}
			curr = curr->next;
		}
	}
}

void print(){
	Node* curr = head;
	while(curr!=NULL){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	printf("NULL\n");
	if(head!=NULL){
		printf("Head: %d\n", head->val);
	}
	if(tail!=NULL){
		printf("Tail : %d\n", tail->val);
	}
}

void popHead(){
	if(head==NULL){
		return;
	}else if(head==tail){
		free(head);
		head = NULL;
		tail = NULL;
	}else{
		Node *temp = head->next;
		//Node *temp = head
		free(head);
		head = temp;
	}
}

void popTail(){
	if(head==NULL){
		return;
	}else if(head==tail){
		free(head);
		head = NULL;
		tail = NULL;
	}else{
		Node *curr = head;
		while(curr->next !=NULL){
			if(curr->next == tail){
				curr->next = NULL;
				free(tail);
				tail = curr;
				return;
			}
			curr = curr->next;
		}
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

void search(int val){
	Node* curr = head;
	while(curr!=NULL){
		if(curr->val == val){
			printf("Found %d\n", curr->val);
			return;
		}
		curr = curr->next;
	}
}

void pushStack(int val){
	pushHead(val);
}

void popStack(){
	popHead();
}

int main()
{
//	pushMid(1);
//	
//	pushMid(3);
//	
//	pushMid(7);
//	
//	pushMid(5);
//	
//	pushMid(4);
//	
//	pushMid(8);
//	
//	pushMid(100);
//	print();
//	
//	popHead();
//	print();
//	
//	popTail();
//	print();
//	
//	popMid(5);
//	print();
//	
//	search(7);
	
//	pushStack(1);
//	pushStack(4);
//	pushStack(9);
//	pushStack(12);
//	pushStack(20);
//	print();
//	popStack();
//	print();
	
//pushMid(1);
//	
//	pushTail(3);
	
	pushHead(-1);
	pushHead(8);
//	popTail();
	
//	pushMid(5);
//	
//	pushMid(4);
//	
//	pushMid(8);
//	
//	pushMid(100);
	print();
	
	return 0;
}
