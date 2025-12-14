#include<stdlib.h>
#include<stdio.h>

struct Node{
	int value, bf, height;
	Node *left, *right;
} *root = NULL;

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->bf = 0;
	newNode->height = 1;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *updateNode(Node *root){
	if(root == NULL) return NULL;
	
	int left = root->left != NULL ? root->left->height : 0;
	int right = root->right ? root->right->height : 0;
	
	root->height = (left > right ? left : right)+1;
	root->bf = left - right;
	return root;
}

Node *leftRotation(Node *oldRoot){
	if(oldRoot==NULL) return NULL;
	
	Node *newRoot = oldRoot->right;
	Node *temp = newRoot->left;
	
	newRoot->left = oldRoot;
	oldRoot->right = temp;
	updateNode(oldRoot);
	updateNode(newRoot);
	return newRoot;
}

Node *rightRotation(Node *oldRoot){
	if(oldRoot==NULL) return NULL;
	
	Node *newRoot = oldRoot->left;
	Node *temp = newRoot->right;
	
	newRoot->right = oldRoot;
	oldRoot->left = temp;
	
	updateNode(oldRoot);
	updateNode(newRoot);
}

Node *rotation(Node *root){
	if(root==NULL) return NULL;
	
	if(root->bf <= -2){
		if(root->right->bf >= 1){
			root->right = rightRotation(root->right);
		}
		return leftRotation(root);
	}else if(root->bf >= 2){
		if(root->left->bf <= -1){
			root->left = leftRotation(root->left);
		}
		return rightRotation(root);
	}
	return root;
}

Node *insert(Node *root, int value){
	if(root == NULL){
		root = createNode(value);
	}else if(root->value > value){
		root->left = insert(root->left, value);
	}else if(root->value == value){
		printf("Node Exist");
	}else{
		root->right = insert(root->right, value);
	}
	updateNode(root);
	return rotation(root);
}

void print(Node *root, int tab){
	if(root==NULL) return;
	
	print(root->right, tab+1);
	for(int i=0; i<tab; i++){
		printf("\t");
	}
	printf("%d(%d, %d)\n", root->value, root->height, root->bf);
	print(root->left, tab+1);
}

Node *predecessor(Node *root){
	Node *curr = root->left;
	while(curr->right){
		curr = curr->right;
	}
	return curr;
}

Node *deleteNode(Node *root, int value){
	if(root == NULL){
		puts("Node Doesnt Exist"); getchar();
		return root;
	}
	
	if(root->value > value){
		root->left = deleteNode(root->left, value);
	}else if(root->value < value){
		root->right = deleteNode(root->right, value);
	}else{
		if(!root->left || !root->right){
			Node* newRoot = root->left ? root->left : root->right;
			root->left = root->right = NULL;
			free(root);
			root = NULL;
			return newRoot;
		}
	Node *inOrderPredecessor = predecessor(root);
    root->value = inOrderPredecessor->value;
    root->left = deleteNode(root->left, inOrderPredecessor->value);
	}
	return rotation(updateNode(root));
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
	print(root, 0);
	root = deleteNode(root, 20);
	root = deleteNode(root, 10);
	print(root, 0);
	
	return 0;
}
