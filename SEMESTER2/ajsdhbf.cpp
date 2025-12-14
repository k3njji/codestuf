#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

char ans[100];

typedef struct stack{
	char val;
	stack *next;
}stack;
stack *head=NULL, *top=NULL;

int j=0;

stack *makeStack(char val){
	stack *newNode = (stack*)malloc(sizeof(stack));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
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
		 if(top->val!='(') ans[j++] = top->val;
    	top = head = NULL;
    	free(head);
	}else{
        if(top->val!='(') ans[j++] = top->val;
        stack *curr = head;
        while(curr->next != top){
            curr = curr->next;
        }
        curr->next = NULL;
        free(top);
        top = curr;
    }
}

void postfix(char infix[]){
	for(int i=0; i<strlen(infix); i++){
		if(infix[i]>='0' && infix[i]<='9'){
			ans[j++] = infix[i];
		}else if(oper(infix[i])==1){
			while(top!=NULL && (precedence(top->val) >= precedence(infix[i]))){
				pop();
			}
			push(infix[i]);
		}else if(infix[i]=='('){
			push(infix[i]);
		}else if(infix[i]==')'){
			while(top->val!='(' && (precedence(top->val) >= precedence(infix[i]))){
				pop();
			}
			pop();
		}
	}
	while(top){
		pop();
	}
}

int main()
{
	puts("Type The Infix to Make it a Postfix");
	char infix[100];
	scanf("%s", infix);
	postfix(infix);
	printf("%s", ans);
	
	return 0;
}

