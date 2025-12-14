#include<stdio.h>
#include<stdlib.h>

struct Node{
	int bf, value, height;
	Node *left, *right;
} *root = NULL;

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->height = 1;
	newNode->bf = 0;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

Node *updateNode(Node *curr){
	if(root == NULL) return NULL;
	int left = curr->left != NULL ? curr->left->height : 0;
	int right = curr->right != NULL ? curr->right->height : 0;
	
	curr->height = (left > right ? left : right) + 1;
	curr->bf = left-right;
	return curr;
}

Node *leftRotate(Node *curr){
	if(curr == NULL) return NULL;
	
	Node *newRoot = curr->right;
	Node *temp = newRoot->left;
	
	newRoot->left = curr;
	curr->right = temp;
	
	updateNode(curr);
	updateNode(newRoot);
	return newRoot;
}

Node *rightRotate(Node *curr){
	if(curr == NULL) return NULL;
	
	Node *newRoot = curr->left;
	Node *temp = newRoot->right;
	
	newRoot->right = curr;
	curr->left = temp;
	
	updateNode(curr);
	updateNode(newRoot);
	return newRoot;
}

Node *rotation(Node *curr){
	if(curr == NULL) return NULL;
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
	}else{
		puts("Duplicate");
	}
	
	updateNode(curr);
	return rotation(curr);
}

Node *prede(Node *curr){
	Node *temp = curr->left;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

Node *del(Node *curr, int value){
	if(curr->value > value){
		curr->left = del(curr->left, value);
	}else if(curr->value < value){
		curr->right = del(curr->right, value);
	}else{
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
			return NULL;
		}else if(!curr->left || !curr->right){
			Node *temp = curr->left != NULL ? curr->left : curr->right;
			free(curr);
			curr = NULL;
			return temp;
		}else{
			Node *temp = prede(curr);
			curr->value = temp->value;
			curr->left = del(curr->left, temp->value);
		}
	}
	return rotation(updateNode(curr));
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
	root = insert(root, 10);
	root = insert(root, 5);
	root = insert(root, 1);
	root = del(root, 5);
	print(root, 0);
	
	return 0;
}
