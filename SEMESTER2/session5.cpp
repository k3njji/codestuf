#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

struct Node {
    char val;
    Node* next, *prev;
} *tail=NULL, *head=NULL, *bigHead=NULL, *bigTail=NULL;

Node* makeNode(char val){
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->val = val;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void pushHead(char val){
    Node* newNode = makeNode(val);
    if(!head){
        head = tail = newNode;
    }else{
        head->prev = newNode;
        newNode->next = head;
        head = newNode;
    }
}

void pushTail(char val){
    Node* newNode = makeNode(val);
    if(!head){
        head = tail = newNode;
    }else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}

void pushMid(char val){
    if(!head || val <= head->val){
        pushHead(val);
    }else if(val >= tail->val){
        pushTail(val);
    }else{
        Node* newNode = makeNode(val);
        Node* curr = head;
        while (curr != tail){
            if (curr->next->val >= val){
                newNode->prev = curr;
                newNode->next = curr->next;
                curr->next->prev = newNode;
                curr->next = newNode;
                return;
            }
            curr = curr->next;
        }
    }
}

void pushBigHead(){
    Node* newNode = makeNode(tail->val);
    if (!bigHead){
        bigHead = bigTail = newNode;
    }else{
        bigTail->next = newNode;
        newNode->prev = bigTail;
        bigTail = newNode;
        }
    }

void popTail(){
	Node *curr = tail;
	while(curr != NULL){
		pushBigHead();
		if(head==tail){
			tail = head = NULL;
			free(head);
		}else{
			Node *temp = tail->prev;
			temp->next = NULL;
			tail->prev = NULL;
			free(tail);
			tail = temp;
		}
		curr = tail;
	}
}

void print(){
	Node *curr = head;
	while(curr!=NULL){
		printf("%c", curr->val);
		curr = curr->next;
	}
	printf(" ");
}

void printBigHead(){
	Node *curr = bigHead;
	while(curr!=NULL){
		printf("%c", curr->val);
		curr = curr->next;
	}
}

int main()
{
	char a;
	while(true)
	{
		scanf("%c", &a);
		a = tolower(a);
		if(a=='\n'){
			print();
			popTail();
			printf("-> (reverse) -> ");
			printBigHead();
			break;
		}else if(a==' '){
			print();
			pushHead(a);
			popTail();
		}else{
			pushMid(a);
		}
	}
	return 0;
}

