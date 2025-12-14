#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int val;
	Node *next;
};

Node *makeNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = value;
	newNode->next = NULL;
	
	return newNode;
}

void pushHead(Node **head, Node **tail, int val){
    Node *newNode = makeNode(val);
    if(*head == NULL){
        *head = *tail = newNode;
    } else {
        newNode->next = *head;
        *head = newNode;
    }
}

//void pushTail(Node *head, Node *tail, int val){
//	Node *newNode = makeNode(val);
//	if(!head){
//		head = tail = newNode;
//	}else{
//		tail->next = newNode;
//		tail = newNode;
//	}
//}
//
//void pushMid(Node *head, Node *tail, int val){
//	Node *newNode = makeNode(val);
//	if(head->val > val || !head){
////		pushHead(head, tail, val);
//	}else if(tail->val < val){
//		pushTail(head, tail, val);
//	}else{
//		Node *curr = head;
//		while(curr){
//			if(curr->next->val > val){
//				newNode->next = curr->next;
//				curr->next = newNode;
//				return;
//			}
//			curr = curr->next;
//		}
//	}
//}

void print(Node *head, Node *tail){
    if(head == NULL){
        printf("List is empty\n");
        return;
    }
    
    Node* curr = head;
    while(curr!=NULL){
        printf("%d ", curr->val);
        curr = curr->next;
    }
}

int main()
{
	Node **head = NULL;
	Node **tail = NULL;
	pushHead(**head, **tail, 8);
	pushHead(**head, **tail, 10);
	
	print(head, tail);
	
	return 0;
}
