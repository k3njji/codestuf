#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>  // for isdigit() function

struct Node{
    char val;
    Node *next;
    Node *prev;
} *head = NULL, *tail = NULL, *tailOp = NULL;

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
        tailOp = newNode;
    }else{
        newNode->next = tailOp;
        tailOp = newNode;
    }
}

char oper(char val){
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
    return -1;  // invalid operator
}

void postfix(char word[]){
    for(int i=0; i<strlen(word); i++){
        if(isdigit(word[i])){
            push(word[i]);
        }else if(oper(word[i]) == 1){
            while(tailOp && precedence(tailOp->val) >= precedence(word[i])){
                push(tailOp->val);
                tailOp = tailOp->next;
            }
            pushOp(word[i]);
        }
    }
    while(tailOp){
        push(tailOp->val);
        tailOp = tailOp->next;
    }
}

void print(){
    Node *curr = head;
    while(curr){
        printf("%c ", curr->val);
        curr = curr->next;
    }
//    printf("\n");
}

int evaluate(){
    int result = 0;
    Node *curr = head;
    while(curr){
        if(isdigit(curr->val)){
            int num = curr->val - '0';
            while(curr->next && isdigit(curr->next->val)){
                num = num * 10 + (curr->next->val - '0');
                curr = curr->next;
            }
            push(num);
        }else if(oper(curr->val) == 1){
            int op2 = head->val - '0';
            head = head->next;
            int op1 = head->val - '0';
            head = head->next;
            switch(curr->val){
                case '+':
                    push(op1 + op2);
                    break;
                case '-':
                    push(op1 - op2);
                    break;
                case '*':
                    push(op1 * op2);
                    break;
                case '/':
                    push(op1 / op2);
                    break;
                case '^':
                    push(op1 ^ op2);
                    break;
            }
        }
        curr = curr->next;
    }
    result = head->val - '0';
    return result;
}

int main()
{
    char word[1000];
    printf("Type the infix notation: ");
    scanf("%s", &word);
    postfix(word);
    
    printf("Postfix notation:");
    print();
}
