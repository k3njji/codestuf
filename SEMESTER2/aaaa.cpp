
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

struct Stack{
	char value;
	Stack* next;
};

Stack* head=NULL;
Stack* tail=NULL;
Stack* headRes=NULL;
Stack* tailRes=NULL;
Stack* headOp=NULL;
Stack* tailOp=NULL;


Stack* makeStack(char value){
	Stack *newStack = (Stack*) malloc(sizeof(Stack));
	newStack->value=value;
	newStack->next=NULL;
	return newStack;
}

void push(char value){
	Stack* newStack = makeStack(value);
	if(head==NULL){
		newStack->next=NULL;
		head=newStack;
		tail=newStack;
	}else{
		newStack->next=head;
		head=newStack;
	}
}

void pushRes(char value){
	Stack* newStack = makeStack(value);
	if(headRes==NULL){
		newStack->next=NULL;
		headRes=newStack;
		tailRes=newStack;
	}else{
		newStack->next=headRes;
		headRes=newStack;
	}
}

void pushOp(char value){
	Stack* newStack = makeStack(value);
	if(headOp==NULL){
		newStack->next=NULL;
		headOp=newStack;
		tailOp=newStack;
	}else{
		newStack->next=headOp;
		headOp=newStack;
	}
}

void print(){
	Stack* curr=head;
	while(curr!=NULL){
		printf("%c", curr->value);
		curr=curr->next;
	}
}

void printOp(){
	Stack* curr=headOp;
	while(curr!=NULL){
		printf("%c", curr->value);
		curr=curr->next;
	}
}

void printRes(){
	Stack* curr=headRes;
	while(curr!=NULL){
		printf("%c", curr->value);
		curr=curr->next;
	}
}

void pop(){
	if(head==NULL){
		return;
	}else if(head==tail){
		free(head);
		head=NULL;
		tail=NULL;
	}else{
		Stack* temp=head->next;
		free(head);
		head=temp;
	}
}

void popOp(){
	if(headOp==NULL){
		return;
	}else if(headOp==tailOp){
		free(headOp);
		headOp=NULL;
		tailOp=NULL;
	}else{
		Stack* temp=headOp->next;
		free(headOp);
		headOp=temp;
	}
}

int getPriority(char op){
	if(op=='^'){
		return 3;
	}else if(op=='/'||op=='*'||op=='%'){
		return 1;
	}else if(op=='+'||op=='-'){
		return 0;
	}
}

void infixToPrefix(){
	while(head!=NULL){
		if(head->value=='('){
			pushOp('(');
			pop();
		}else if(head->value==')'){
			while(headOp->value!='('){
				pushRes(headOp->value);
				popOp();
				}
			popOp();
			pop();
		}else if(isdigit(head->value)||isalpha(head->value)){
			pushRes(head->value);
			pop();
		}else if(head->value=='+'||head->value=='-'||head->value=='*'||head->value=='/'||head->value=='%'||head->value=='^'){
			while((headOp->value!='(')&&(getPriority(headOp->value)>getPriority(head->value))){
				pushRes(headOp->value);
				popOp();
			}
			pushOp(head->value);
			pop();
		}
	}
}

int main(){
	char infix[100];
	printf("Enter infix notation: ");
	scanf("%[^\n]", infix);
	int len=strlen(infix);
	push(')');
	for(int i=0;i<len;i++){
		if(infix[i]=='('){
			push(')');
		}else if(infix[i]==')'){
			push('(');
		}else if(infix[i]!=' '){
			push(infix[i]);
		}
	}
	push('(');
	infixToPrefix();
	printf("Converted into prefix: ");
	printRes();
	puts("");
	return 0;
}
