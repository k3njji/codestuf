#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	Node *left, *right;
};

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

Node *push(Node *root, int val){
	if(!root){
		return makeNode(val);
	}else if(root->val > val){
		root->left = push(root->left, val);
	}else if(root->val < val){
		root->right = push(root->right, val);
	}else{
		puts("exist");
		return root;
	}
}

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		printf("%d ", root->val);
		inOrder(root->right);
	}
}

void postOrder(Node *root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->val);
	}
}

void preOrder(Node *root){
	if(root){
		printf("%d ", root->val);
		preOrder(root->left);
		preOrder(root->right);
	}
}

int main()
{
	Node *root = NULL;
	root = push(root, 8);
	root = push(root, 4);
	root = push(root, 10);
	root = push(root, 3);
	root = push(root, 1);
	root = push(root, 15);
	root = push(root, 9);
	root = push(root, 13);
	root = push(root, 12);
	
	inOrder(root);
	puts("");
	preOrder(root);
	puts("");
	postOrder(root);
	
	return 0;
}
