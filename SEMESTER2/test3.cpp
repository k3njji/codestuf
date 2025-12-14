#include<stdlib.h>
#include<stdio.h>

struct Node{
	int value, bf, height;
	Node *left, *right;
};

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	newNode->bf = 0;
	newNode->height = 1;
	return newNode;
}

void updateNode(Node *root){
	if(root == NULL) return;
	int left = root->left != NULL ? root->left->height : 0;
	int right = root->right ? root->right->height : 0;
	
	root->height = (left > right ? left : right)+1;
	root->bf = left - right;
}

Node *leftRotate(Node *oldRoot){
	if(oldRoot==NULL) return NULL;
	
	Node *newRoot = oldRoot->right;
	Node *temp = newRoot->left;
	
	newRoot->left = oldRoot;
	oldRoot->right = temp;
	
	updateNode(oldRoot);
	updateNode(newRoot);
	return newRoot;
}

Node *rightRotate(Node *oldRoot){
	if(oldRoot==NULL) return NULL;
	
	Node *newRoot = oldRoot->left;
	Node *temp = newRoot->right;
	
	newRoot->right = oldRoot;
	oldRoot->left = temp;
	
	updateNode(oldRoot);
	updateNode(newRoot);
	return newRoot;
}

Node *rotation(Node *curr){
	if(curr==NULL) return NULL;
	
	if(curr->bf <= -2){
		if(curr->right->bf >= 1){
			curr->right = rightRotate(curr->right);
		}
		return leftRotate(curr);
	}else if(curr->bf >= 2){
		if(curr->left->bf <= -1){
			curr->left = leftRotate(curr->left);
		}
		return rightRotate(curr);
	}
	return curr;
}

Node *insert(Node *root, int value){
	if(root==NULL){
		return createNode(value);
	}else if(root->value < value){
		root -> right = insert (root->right, value);
	}else if(root->value > value){
		root -> left = insert (root->left, value);
	}else{
		puts("Duplicate");
	}
	updateNode(root);
	
	return rotation(root);
}

void print(Node *root, int tab, char name){
	if(root==NULL) return;
	
	print(root->right, tab+1, '/');
//	if(name == '\\') printf("%c\n", name);
	for(int i=0; i<tab; i++){
		printf("\t");
	}
	printf("%d(%d, %d)\n", root->value, root->height, root->bf);
//	for(int i=0; i<tab; i++){
//		printf("\t");
//	}
//	if(name == '/')printf("%c\n", name);
	print(root->left, tab+1, '\\');
}

int main()
{
	Node *root = NULL;
	root = insert(root, 10);
	root = insert(root, 30);
	root = insert(root, 20);
	root = insert(root, 5);
	root = insert(root, 100);
	root = insert(root, 25);
	root = insert(root, 12);
	print(root, 0, NULL);
	
	
	
	return 0;
} 
