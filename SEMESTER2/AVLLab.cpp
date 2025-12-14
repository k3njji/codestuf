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

Node *updateNode(Node *root){
	if(root == NULL) return NULL;
	int left = root->left != NULL ? root->left->height : 0;
	int right = root->right ? root->right->height : 0;
	
	root->height = (left > right ? left : right)+1;
	root->bf = left - right;
	return root;
}

Node *leftRotate(Node *oldRoot){
	if(oldRoot==NULL) return NULL;
	
	Node *newRoot = oldRoot->right;
	Node *temp = newRoot->left
	
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

Node *rotation(Node *root){
	if(root==NULL) return NULL;
	
	if(root->bf <= -2){
		if(root->right->bf >= 1){
			root->right = rightRotate(root->right);
		}
		return leftRotate(root);
	}else if(root->bf >= 2){
		if(root->left->bf <= -1){
			root->left = leftRotate(root->left);
		}
		return rightRotate(root);
	}
	return root;
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

Node *predecessor(Node *curr){
	Node *temp = curr->left;
	while(temp->right){
		temp = temp->right;
	}
	return temp;
}

Node *removeNode(Node *curr, int value){
	if(curr == NULL) return curr;
	
	if(value < curr->value) curr->left = removeNode(curr->left, value);
	else if(value > curr->value) curr->right = removeNode(curr->right, value);
	else{
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
			return NULL;
		}else if(!curr->left || !curr->right){
			Node *temp = (!curr->left) ? curr->right : curr->left;
			free(curr);
			curr = NULL;
			return temp;
		}else{
			Node *temp = predecessor(curr);
			curr->value = temp->value;
			curr->left = removeNode(curr->left, temp->value);
		}
	}
	return rotation(updateNode(curr));
}

Node *updateNode(Node *curr, int value, int newValue){
	Node *temp = NULL;
	temp = removeNode(curr, value);
	temp = insert(temp, newValue);
	return temp;
}

void print(Node *root, int level){
    if (root == NULL) return;
    print(root->right, level + 1);
    for(int i=0; i<level; i++) {
        printf("    ");
	}
    printf("|-- %d\n", root->value);
    print(root->left, level + 1);
}

int main()
{
	Node *root = NULL;
	root = insert(root, 20);
	root = insert(root, 30);
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 15);
	root = insert(root, 25);
	root = insert(root, 35);
//	root = removeNode(root, 30);
//	root = updateNode(root, 20, 1);
	print(root, 0);
	
	return 0;
}
