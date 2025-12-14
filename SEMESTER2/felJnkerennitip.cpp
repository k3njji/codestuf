#include <stdio.h>
#include <stdlib.h>

struct Node{
	int number;
	int height;
	int bf;
	struct Node *left;
	struct Node *right;
};

struct Node *createNewNode(int number){
	struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
	
	temp->number = number;
	temp->height = 1;
	temp->bf = 0;
	temp->left = NULL;
	temp->right = NULL;
	
	return temp;
};

int maxHeight(int a, int b){
	return a > b ? a : b;
}

int nodeHeight(struct Node *root){
	if(root == NULL){
		return NULL;
	}
	
	return root->height;
}

int balanceFactor(struct Node *root){
	if(root == NULL){
		return NULL;
	}
	
	return nodeHeight(root->left) - nodeHeight(root->right);
}

struct Node *updateNode(struct Node *root){
	root->height = maxHeight(nodeHeight(root->left), nodeHeight(root->right)) + 1;
	root->bf = balanceFactor(root);
	
	return root;
}

struct Node *leftRotate(struct Node *root){
	struct Node *rightNode = root->right;
	struct Node *temp = rightNode->left;
	
	rightNode->left = root;
	root->right = temp;
	
	root = updateNode(root);
	rightNode = updateNode(rightNode);
	
	return rightNode;
}

struct Node *rightRotate(struct Node *root){
	struct Node *leftNode = root->left;
	struct Node *temp = leftNode->right;
	
	leftNode->right = root;
	root->left = temp;
	
	root = updateNode(root);
	leftNode = updateNode(leftNode);
	
	return leftNode;
}

struct Node *rebalanceRotation(struct Node *curr){
	if(curr->bf < -1 && curr->right->bf <= 0){
		return leftRotate(curr);
	}
	else if(curr->bf < -1 && curr->right->bf > 0){
		curr->right = rightRotate(curr->right);
		return leftRotate(curr);
	}
	else if(curr->bf > 1 && curr->left->bf >= 0){
		return rightRotate(curr);
	}
	else if(curr->bf > 1 && curr->left->bf < 0){
		curr->left = leftRotate(curr->left);
		return rightRotate(curr);
	}
	return curr;
}

struct Node *insertion(struct Node *root, int number){
	if(root == NULL){
		return createNewNode(number);
	}
	else if(root->number > number){
		root->left = insertion(root->left, number);
	}
	else if(root->number < number){
		root->right = insertion(root->right, number);
	}
	
	root = updateNode(root);
	return rebalanceRotation(root);
}

struct Node *deletion(struct Node *root, int number){
	if(root == NULL){
		printf("Data Not Found!\n");
		return NULL;
	}
	else if(root->number > number){
		root->left = deletion(root->left, number);
	}
	else if(root->number < number){
		root->right = deletion(root->right, number);
	}
	else{
		if(root->right == NULL){
			struct Node *temp = root->left;
			free(root);
			root = NULL;
			return temp;
		}
		else if(root->left == NULL){
			struct Node *temp = root->right;
			free(root);
			root = NULL;
			return temp;
		}
		else{
			struct Node *temp = root->left;
			
			while(temp->right != NULL){
				temp = temp->right;
			}
			
			root->number = temp->number;
			root->left = deletion(root->left, temp->number);
		}
	}
	
	root = updateNode(root);
	return rebalanceRotation(root);
}

void preOrder(struct Node *root){
	if(root == NULL){
		return;
	}
	else{
		printf("Value: %d | BF: %d | H: %d\n", root->number, root->bf, root->height);
		preOrder(root->left);
		preOrder(root->right);
	}
}

void inOrder(struct Node *root){
	if(root == NULL){
		return;
	}
	else{
		inOrder(root->left);
		printf("Value: %d | BF: %d | H: %d\n", root->number, root->bf, root->height);
		inOrder(root->right);
	}
}

void postOrder(struct Node *root){
	if(root == NULL){
		return;
	}
	else{
		postOrder(root->left);
		postOrder(root->right);
		printf("Value: %d | BF: %d | H: %d\n", root->number, root->bf, root->height);
	}
}

int main(){
	struct Node *root = NULL;
	
	root = insertion(root, 4);
	root = insertion(root, 1);
	
	root = insertion(root, 2);
	
	puts("pre order:");
	preOrder(root);
	puts("");
	
	puts("in order:");
	inOrder(root);
	puts("");
	
	puts("post order:");
	postOrder(root);
	puts("");
	
	return 0;
}
