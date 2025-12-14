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
        push(tailOp->val);
        Node* prev = tailOp->prev;
        free(tailOp);
        tailOp = prev;
        if(tailOp) {
            tailOp->next = NULL;
        }
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

//void check(){
//	Node *temp = headOp;
//	while()
//}

void postfix(char word[]){
    for(int i=0; i<strlen(word); i++){
        if(word[i] >= '0' && word[i] <='9'){
            push(word[i]);
        }else if(oper(word[i]) == 1){
        	if(tailOp==NULL){
        		pushOp(word[i]);
			}else{
				
			}
        }
    }
    pop();
//    Node* curr = tailOp;
//    while(tailOp){
//    	pop();
//    	tailOp = tailOp->prev;
//	}
}

void print(){
    Node *curr = head;
    while(curr){
        printf("%c", curr->val);
        curr = curr->next;
    }
    puts("");
}

int main()
{
    char word[1000];
    printf("Type the infix notation: ");
    scanf("%s", word);
    postfix(word);
    print();
    return 0;
}
