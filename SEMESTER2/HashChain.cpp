#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<ctype.h>

const int max = 27;

struct Node{
	char name[100];
	Node *next;
} *data[max]={NULL};

int function(char name[]){
	return abs((name[0]-97)%max);
}

Node *makeNode(char lol[]){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, lol);
	newNode->next = NULL;
	return newNode;
}

void push(char lol[]){
	
	int key = function(lol);
	Node *newNode = makeNode(lol);
		
	if(data[key]==NULL){
		data[key] = newNode;
	}else{
		Node *temp = data[key];
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = newNode;
	}
}

void pop(char lol[]){
	int key = function(lol);
	if(data[key]==NULL){
		return;
	}else if(strcmp(lol, data[key]->name)==0){
		free(data[key]);
		data[key]=NULL;
	}else{
		Node *curr = data[key];
		while(curr){
			if(strcmp(curr->next->name, lol)==0){
				Node *temp = curr->next->next;
				free(curr->next);
				curr->next = temp;
			}
			curr = curr->next;
		}
	}
}

void popALL(){
	for(int i=0; i<max; i++){
		Node *curr = data[i];
		while(curr){
			Node *temp = curr->next;
			free(curr);
			curr = temp;
		}
		data[i] = NULL;
	}
}



int search(char lol[]){
	int key = function(lol);
	if(data[key]==NULL){
		return -1;
	}else if(strcmp(data[key]->name, lol)==0){
		return key;
	}else{
		Node *curr = data[key];
		while(curr){
			if(strcmp(curr->name, lol)==0){
				return key;
			}
			curr = curr->next;
		}
	}
	return -1;
}

void print(){
	for(int i=0; i<max; i++){
		printf("[%d] ", i);
  		Node *temp = data[i];
		while(temp){
			printf("%s -> ",  temp->name);
			temp = temp->next;
		}
		printf("NULL");
		puts("");
	}
}

int main()
{
	while(1){
		char name[100];
		char temp[100];
		scanf("%s", name); getchar();
		if(strcmp(name, "exit")==0){
			break;
		}else if(strcmp(name, "pop")==0){
			scanf("%s", temp);
			pop(temp);
			print();
		}else if(strcmp(name, "search")==0){
			scanf("%s", temp);
			int x = search(temp);
			if(x==-1){
				puts("not found");
			}else{
				printf("found at %d\n", x);
			}
		}else if(strcmp(name, "all")==0){
			popALL();
			print();
		}else{
		push(name);
		print();
		}
	}
	return 0;
}
