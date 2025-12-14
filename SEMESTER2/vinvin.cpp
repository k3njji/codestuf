#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
    char value;
    struct Node *next, *prev;
}*head, *tail, *tail2, *head2, *top;

struct Node *createNode(char value){
    struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

int check(char value){
    if(value == '^'){
        return 3;
    }
    else if(value == '*' || value ==  '/'){
        return 2;
    }
    else if(value == '+' || value == '-'){
        return 1;
    }
    return -1;
}

void pushhead(char value){
    struct Node *curr = createNode(value);
    if(!head){
        head = tail = curr;
    }
    else{
        curr->next = head;
        head = curr;
    }
}
void pushTail(char value){
    struct Node *curr = createNode(value);
    if(!head){
        head = tail = curr;
    }
    else{
        tail->next = curr;
        tail = curr;
        tail->next = NULL;
    }
}

void pushTop(char value){
    struct Node *curr = createNode(value);
    if(!top){
        top = curr;
    }
    else{
        curr->next = top;
        top = curr;
    }
}

void popTop(){
    if(!top){
        return; // check if top is not NULL
    }
    struct Node* temp = top->next;
    free(top);
    top = temp;
}

void popHead(){
	if(head==NULL){
		return;
	}
	else if(head == tail){
		free(head); // untuk hilangin memory dan hanya berguna ketika ada alloc alloc
		head = tail = NULL;
	}
	else{
		Node* temp = head->next;
		free(head);
		head = temp;
	}
}

void postfix(){
    char equation;
    while(1){
        scanf("%c", &equation);
        if((equation >= '0' && equation <= '9'))
        {
            pushTail(equation);
        }
        else if(check(equation) >= 0){
            if(top!=NULL && (check(top->value) >= check(equation))){
                pushTail(top->value);
                popTop();
            }
            pushTop(equation);
        }
        else if(equation == '('){
            pushTop(equation);
        }else if(equation==')'){
            while(top->value!='(' && check(top->value) >= check(equation)){
                pushTail(top->value);
                popTop();
            }
            popTop();
        }
        if(equation == '\n'){
            break; // exit the input scanning loop
	    }
	}
	    while(top){
	        	pushTail(top->value);
	        	popTop();
		    }
}

void prefix(){
    char equation [10000];
        scanf("%s", equation);
        strrev(equation);
    for(int i=0; i<strlen(equation); i++){
        if((equation[i] >= '0' && equation[i] <= '9'))
        {
            pushhead(equation[i]);
        }
        else if(check(equation[i]) >= 0){
            if(top!=NULL && (check(top->value) > check(equation[i]))){
                pushhead(top->value);
                popTop();
            }
            pushTop(equation[i]);
        }
        else if(equation[i] == ')'){
            pushTop(equation[i]);
        }else if(equation[i]=='('){
            while(top->value!=')' && (check(top->value) >= check(equation[i]))){
                pushhead(top->value);
                popTop();
            }
            popTop();
        }
    }
 while(top){
        	pushhead(top->value);
        	popTop();
    }
}

void print(){
	Node *curr = head;
	while(curr!=NULL){
		printf("%c", curr->value);
		curr = curr->next;
	}
	printf(" ");
	while(head!=NULL){
	popHead();
	}
}

int main(){
	postfix();
	printf("Postfix: ");
	print();
	puts("");
	prefix();
	printf("Prefix: ");
	print();
	return 0;
}


