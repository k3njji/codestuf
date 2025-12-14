#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int value;
	Node *left;
	Node *right;
} *root = NULL;

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node* push(Node *temp, int val){
	Node *newNode = makeNode(val);
	while(temp){
		if(temp->value < val){
			if(temp->right == NULL){
				temp->right = newNode;
				return temp;
			}
			temp = temp->right;
		}else if(temp->value > val){
				if(temp->left == NULL){
				temp->left = newNode;
				return temp;
			}
			temp = temp->left;
		}else if(temp->value == val){
			return temp;
		}
	}
}

void search(Node *temp, int val){
	while(temp!=NULL){
		if(temp->value < val){
			temp = temp->right;
		}else if(temp->value > val){
			temp = temp->left;
		}else if(temp->value == val){
			puts("found");
			return;
		}
	}
	puts("not exist");
}

void inOrder(Node *curr) {
	if(curr != NULL) {
		inOrder(curr->left);
		printf("%d\n", curr->value);
		inOrder(curr->right);
	}
}

int main()
{
	root = push(root, 5);
	push(root, 3);
	push(root, 2);
	push(root, 4);
	push(root, 6);
	inOrder(root);
	search(root, 7);

	return 0;	
}
