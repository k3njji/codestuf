#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct Node{
	int value, bf, height;
	Node *left, *right;
} *root=NULL;

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	newNode->bf = 0;
	
	return newNode;
}

Node *updateNode(Node *curr){
	int left = curr->left != NULL ? curr->left->height : 0;
	int right = curr->right != NULL ? curr->right->height : 0;
	
	curr->bf = left - right;
	curr->height = (left > right ? left : right)+1;
	
	return curr;
}

Node *leftRotate(Node *curr){
	Node *newRoot = curr->right;
	Node *temp = newRoot->left;
	
	newRoot->left = curr;
	curr->right = temp;
	
	updateNode(curr);
	updateNode(newRoot);
	return newRoot;
}

Node *rightRotate(Node *curr){
	Node *newRoot = curr->left;
	Node *temp = newRoot->right;
	
	newRoot->right = curr;
	curr->left = temp;
	
	updateNode(curr);
	updateNode(newRoot);
	return newRoot;
}

Node *balance(Node *curr){
	if(curr->bf >= 2){
		if(curr->left->bf <= -1){
			curr->left = leftRotate(curr->left);
		}
		return rightRotate(curr);
	}else if(curr->bf <= -2){
		if(curr->right->bf >= 1){
			curr->right = rightRotate(curr->right);
		}
		return leftRotate(curr);
	}
	
	return curr;
}

Node *insert(Node *curr, int value){
	if(curr == NULL){
		return createNode(value);
	}else if(curr->value > value){
		curr->left = insert(curr->left, value);
	}else if(curr->value < value){
		curr->right = insert(curr->right, value);
	}
	
	updateNode(curr);
	return balance(curr);
}

void print(Node *curr){
	if(curr==NULL) return;
	
	print(curr->left);
	printf("%d\n", curr->value);
	print(curr->right);
}

int main()
{
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 1);
	print(root);
	
	return 0;
}
