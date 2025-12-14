#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>
#include<string.h>

typedef struct stack{
	char val;
	stack *next;
}stack;
stack *head=NULL, *top=NULL, *headFix=NULL, *tailFix=NULL; 

stack *makeStack(char val){
	stack *newNode = (stack*)malloc(sizeof(stack));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void pushPrefix(char val){
	stack *newNode = makeStack(val);
	if(!headFix){
		headFix = newNode;
	}else{
		newNode->next = headFix;
		headFix = newNode;		
	}
}

void push(char val){
	stack *newNode = makeStack(val);
	if(!top){
		head = top = newNode;
	}else{
		top->next = newNode;
		top = newNode;
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

void pop(){
    if(!top){
        return;
    }else if(top == head){
		 if(top->val!=')') pushPrefix(top->val);
    	top = head = NULL;
    	free(head);
	}else{
        if(top->val!=')')pushPrefix(top->val);
        stack *curr = head;
        while(curr->next != top){
            curr = curr->next;
        }
        curr->next = NULL;
        free(top);
        top = curr;
    }
}

void prefix(char infix[]){
	for(int i=0; i<strlen(infix); i++){
		if(infix[i]>='0' && infix[i]<='9'){
			pushPrefix(infix[i]);
		}else if(oper(infix[i])==1){
			while(top!=NULL && (precedence(top->val) > precedence(infix[i]))){
				pop();
			}
			push(infix[i]);
		}else if(infix[i]==')'){
			push(infix[i]);
		}else if(infix[i]=='('){
			while(top->val!=')' && (precedence(top->val) > precedence(infix[i]))){
				pop();
			}
			pop();
		}
	}
	while(top){
		pop();
	}
}

void print(){
	stack *curr = headFix;
	while(curr){
		printf("%c", curr->val);
		curr = curr->next;
	}
}

int main()
{
	puts("Type The Infix to Make it a Prefix (IN NUMBERS)");
	char infix[100];
	scanf("%s", infix);
	strrev(infix);
	printf("%s\n", infix);
	prefix(infix);
	print();
	
	return 0;
}
