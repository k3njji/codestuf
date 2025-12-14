#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	Node *next;
} *head = NULL, *tail = NULL;

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->next = NULL;
	newNode->val = val;
	
	return newNode;
}

void pushHead(int val){
	Node *newNode = makeNode(val);
	
	if(!head){
		head = tail = newNode;
	}else{
		newNode->next = head;
		head = newNode;
	}
}

void pushTail(int val){
	Node *newNode = makeNode(val);
	
	if(!head){
		head = tail = newNode;
	}else{
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
		while(curr){
			if(curr->next->val > val){
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
		free(head);
		head = tail = NULL;
	}else{
		Node *temp = head->next;
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
		Node *curr = head;
		while(curr->next->next !=NULL){
			curr = curr->next;
		}
		Node *temp = curr->next->next;
		free(curr->next);
		curr->next = temp;
	}
}

void popMid(int val){
	if(head->val == val){
		popHead();
	}else if(tail->val == val){
		popTail();
	}else{
		Node *curr = head;
		while(curr->next != NULL){
			if(curr->next->val == val){
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
	Node *curr = head;
	while(curr){
		if(curr->val == val){
			puts("Found");
			return;
		}
		curr = curr->next;
	}
}

void print(){
	Node *curr = head;
	while(curr){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	puts("NULL");
}

int main()
{
	pushMid(8);
	pushMid(9);
	pushMid(5);
	pushMid(10);
	pushMid(11);
	pushMid(1);
	print();
	
	popHead();
	popTail();
	popMid(20);
//	popMid(8);
//	popMid(10);
	print();
//	search(20);
//	search(9);
	
	return 0;
}
