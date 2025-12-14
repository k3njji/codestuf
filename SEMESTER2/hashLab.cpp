#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Node{
	char ID[10];
	char name[30];
	int age;
	Node *next;
};

int inc = 0;

Node *makeNode(const char name[], int age){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->age = age;
//	sprintf(newNode->ID, "ST%03d", rand()%10);
	sprintf(newNode->ID, "ST%03d", inc++);

	newNode->next = NULL;
	return newNode;
}

const int MAX = 1;

Node *hashTableHead[MAX]={NULL};
Node *hashTableTail[MAX]={NULL};
Node *hashTable[MAX]={NULL};

//simple function
int hashing(char string[]){
	int total = 0;
	for(int i=0; i<strlen(string); i++){
		total =+ string[i];
	}
	return total%MAX;
}

void push(const char name[], int age){
	Node *newNode = makeNode(name, age);
	int key = hashing(newNode->ID);
	if(hashTable[key]==NULL){
//		hashTableHead[key] = hashTableTail[key] = newNode;
		hashTable[key] = newNode;
	}else{
//		hashTableTail[key]->next = newNode;
//		hashTableTail[key] = newNode;
		Node *curr = hashTable[key];
		while(curr){
			if(curr->next == NULL){
				curr->next = newNode;
				return;
			}
			curr = curr->next;
		}
	}
}

void pop(char id[]){
	int idx = hashing(id);
	
	if(hashTable[idx]==NULL){
		return;
	}else if(strcmp(hashTable[idx]->ID, id)==0){
		Node *temp = hashTable[idx]->next;
		hashTable[idx]=NULL;
		free(hashTable[idx]);
		hashTable[idx]=temp;
	}else{
		Node *curr = hashTable[idx];
		puts("a");
		while(curr!=NULL){
			
			if(strcmp(curr->next->ID, id)==0){
				Node *temp = curr->next->next;
				free(curr->next);
				curr->next = temp;
				return;
			}
			curr = curr->next;
		}
		puts("keluar");
	}
}

void print(){
	for(int i=0; i<MAX; i++){
		printf("[%d] ", i);
		Node *curr = hashTable[i];
		while(curr){
			printf("(%s): %s, %d -> ", curr->ID, curr->name, curr->age);
			curr = curr->next;
		}
		puts("");
	}
}

int main()
{	
	srand(time(NULL));
	push("test", 5);
	push("test2", 5);
	print();
		pop("ST002");
	print();
	
	return 0;
}
