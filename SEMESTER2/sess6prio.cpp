#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int val;
	Node *next;
} *head=NULL, *tail = NULL;

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	newNode->next = NULL;
	return newNode;
}

void pushTail(int val){
	Node* newNode = makeNode(val);
	if(!head){
		head  = tail = newNode;
	}else{
		tail->next = newNode;
		tail = newNode;
	}
}

void pop(){
	if(!head){
		return;
	}
	Node *temp = head;
	Node *search = head;
	while(search!=NULL){
		if(temp->val < search->val){
			temp = search;
		}
		search = search->next;
	}
	
	Node *curr = head;
	while(curr){
		if(temp==head){
			Node *temp2 = head->next;
			head->next = NULL;
			free(head);
			head = temp2;
			return;
		}else if(temp == tail){
			Node *temp2 = head;
			while(temp2->next != tail){
				temp2 = temp2->next;
			}
			temp2->next = NULL;
			free(tail);
			tail = temp2;
			return;

		}else{
			Node *raymond = head;
			while(raymond->next!=NULL && raymond->next!=temp){
				raymond = raymond->next;
			}
			raymond->next = temp->next;
			temp->next = NULL;
			free(temp);
			return;
		}
		curr = curr->next;
	}
}

void print(){
	puts("===========================================================");
	Node *curr = head;
	while(curr){
		printf("%d -> ", curr->val);
		curr = curr->next;
	}
	printf("NULL\n");
	puts("===========================================================");
	puts("");
}

int main()
{
	puts("PRIORITY QUEUE");
	puts("==============");
	while(1){
		printf("THE HIGHEST VALUE HAVE THE HIGHEST PRIORITY\n");
		printf("Type \"En\" to Enqueue\n");
		puts("Type \"De\" to Dequeue");
		puts("Type \"Exit\" to Terminate the Program");
		puts("CASE SENSITIVE");
		char word[69];
		scanf("%s", &word);
		if(strcmp(word, "En")==0){
		int x;
		scanf("%d", &x);
		pushTail(x);
		print();
	}else if(strcmp(word, "De")==0){
		pop();
		print();
	}else if(strcmp(word, "Exit")==0){
		puts("Thank You For Using The Program");
	 	break;
	}
	}
	return 0;
}
