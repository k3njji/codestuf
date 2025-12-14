#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<math.h>

const int max = 500;

struct Node{
	char name[500];
} *table[max] = {NULL};

Node* makeNode(char name[]){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	return newNode;
}

int function(char name[]){
	double count = 0;
	
	for(int i=0; i<strlen(name); i++){
		if( (name[i] >='a' && name[i] <= 'z') || (name[i] >='A' && name[i] <= 'Z') ){
			count+=name[i];
		}
	}
	
	double x = (count*0.235);
	
	int key = floor(x);
	return key%max;
}

void push(char name[]){
	Node *newNode = makeNode(name);
	int key = function(name);
	
	if(table[key] == NULL){
		table[key] = newNode;
	}else{
		int index = key;
		key = (key+1)%max;
		
		while(table[key] != NULL && index!=key){
			key = (key+1)%max;
		}
		
		if(table[key] == NULL){
			table[key] = newNode;
		}else{
			puts("data exist");
		}
	}
}

void view(){
	for(int i=0; i<max/2 ; i++){
		if(table[i] != NULL || table[max-i] != NULL){
			printf("[%d] %s || [%d] %s\n", i+1, table[i]->name, max-i, table[max-i]);
		}
	}
}

int main()
{
	int x;
	scanf("%d", &x); getchar();
	for(int i=0; i<x; i++){
		char name[100];
		int len = 0;
		do{
			scanf("%[^\n]", &name); getchar();
			int len = strlen(name);
		} while(len > 50);
		push(name);
	}
	
	view();
	
	return 0;
}
