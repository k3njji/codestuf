#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

//Node* push(Node *temp, int val){
//	Node *newNode = makeNode(val);
//	while(temp!=NULL){
//		if(temp->value < val){
//			if(temp->right == NULL){
//				temp->right = newNode;
//				return temp;
//			}
//			temp = temp->right;
//		}else if(temp->value > val){
//				if(temp->left == NULL){
//				temp->left = newNode;
//				return temp;
//			}
//			temp = temp->left;
//		}else if(temp->value == val){
//			return temp;
//		}
//	}
//}

void push(Node *temp, int val){
	Node *newNode = makeNode(val);
	while(temp->left!=NULL && temp->right!=NULL){
		if(temp->value < val){
			temp = temp->right;
		}else if(temp->value > val){
			temp = temp->left;
		}else if(temp->value == val){
			return;
		}
		temp = newNode;
	}
}

int search(Node *temp, int val){
	while(temp!=NULL){
		if(temp->value < val){
			temp = temp->right;
		}else if(temp->value > val){
			temp = temp->left;
		}else if(temp->value == val){
			return 1;
		}
	}
	return 0;
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
	Node *root = NULL;
	push(root, 5);
	push(root, 3);
	push(root, 2);
	push(root, 4);
	push(root, 6);
	inOrder(root);
//	printf("%d", root->value);
	int vali = search(root, 5);
	
	if(vali==1){
	puts("found");
	}else{
	puts("not exist");	
	}

	return 0;	
}

