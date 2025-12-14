#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	char val;
	Node *next;
	Node *prev;
} *head = NULL, *tail = NULL, *headOp = NULL, *tailOp = NULL;

Node *makeNode(char val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}


void push(char val){
    Node* newNode = makeNode(val);
    if(!head){
        head = tail = newNode;
    }else{
        newNode->prev = tail;
        tail->next = newNode;
        tail = newNode;
    }
}


void pushOp(char val){
	Node *newNode = makeNode(val);
	if(!tailOp){
		headOp = tailOp = newNode;
	}else{
		newNode->prev = tailOp;
		tailOp->next = newNode;
		tailOp = newNode;
	}
}

void pop(){
	if(!tailOp){
		return;
	}else{
		Node* prev = tailOp->prev;
		free(tailOp);
		tailOp = prev;
		tailOp->next = NULL;
	}
}

int oper(char val){
	if(val == '+' || val == '-' || val == '*' || val == '/' || val == '^'){
		return 1;
	}
	return 0;
}

int precedence(char op){
    if(op == '^'){
        return 3;
    }else if(op == '*' || op == '/'){
        return 2;
    }else if(op == '+' || op == '-'){
        return 1;
    }
    return -1;
}



void postfix(char word[]){
	for(int i=0; i<strlen(word); i++){
		if(word[i] >= '0' && word[i] <='9'){
			push(word[i]);
		}else if(oper(word[i]) == 1){
//			int len = precedence(tailOp->val);
//			while(tailOp && len >= precedence(word[i])){
//				push(tailOp->val);
//				tailOp = tailOp->next;
//			}
			pushOp(word[i]);
		}
	}
}

void print(){
	Node *curr = head;
	while(curr){
		printf("%c", curr->val);
		curr = curr->next;
	}
//	puts("");
//	Node *curr2 = headOp;
//	while(headOp){
//	printf("%c", curr2->val);
//	curr2 = curr2->next;
//}
}

int main()
{
	char word[1000];
	printf("Type the infix notation: ");
	scanf("%s", &word);
	postfix(word);
	
	print();
	
//	puts("1. Infix to Postfix");
//	puts("2. Infix to Prefix");
	
	return 0;
}
