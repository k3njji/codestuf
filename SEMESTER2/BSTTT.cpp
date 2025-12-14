#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	Node *left, *right;
} *root = NULL;

Node *makeNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->left = newNode->right = NULL;
	newNode->val = value;
	return newNode;
}

Node *push(Node *root, int value){
	if(root == NULL){
		return makeNode(value);
	}else if(root->val  > value){
		root->left = push(root->left, value);
	}else if(root->val < value){
		root->right = push(root->right, value);
	}else{
		puts("Data Exist");
	}
	return root;
}

Node *predecessor(Node *root){
	Node *curr = root->left;
	
	while(curr){
		if(curr->right == NULL){
			return curr;
		}
		curr = curr->right;
	}
	return NULL;
}

Node *deleteNode(Node *root, int val){
	if(!root){
		puts("Data not Found");
		return root;
	}else if(root->val > val){
		root->left = deleteNode(root->left, val);
		return root;
	}else if(root->val < val){
		root->right = deleteNode(root->right, val);
		return root;
	}else{
		if(root->left && root->right){
			Node *replacement = predecessor(root);
			root->val = replacement->val;
			replacement->val = val;
			root->left = deleteNode(root->left, val);
			return root;
	}else{
		Node *temp = root->left !=NULL ? root->left : root->right;
		free(root);
		return temp;
	}
}

void search(Node *root, int val){
	if(!root){
		puts("Not Found");
	}else if(root->val == val){
		puts("Found");
		return;
	}else if(root->val > val){
		search(root->left, val);
	}else{
		search(root->right, val);
	}
}

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
		printf("%d ", root->val);
		inOrder(root->right);
	}
}

void preOrder(Node *root){
	if(root){
		printf("%d ", root->val);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void postOrder(Node *root){
	if(root){
		postOrder(root->left);
		postOrder(root->right);
		printf("%d ", root->val);
	}
}

int main()
{
	root = push(root, 8);
	root = push(root, 10);
	root = push(root, 4);
	root = push(root, 3);
	root = push(root, 5);
	root = push(root, 9);
	root = push(root, 11);
	root = push(root, 13);
	root = push(root, 12);
	inOrder(root);
	puts("");
	preOrder(root);
	puts("");
	postOrder(root);
	puts("");
//	del(root, 5);
	deleteNode(root, 4);
	search(root, 4);
	inOrder(root);
	
	return 0;
}
