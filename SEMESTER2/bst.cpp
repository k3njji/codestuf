#include<stdio.h>
#include<stdlib.h>

struct Node{
	int val;
	Node *right, *left;
} *root = NULL;

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	newNode->left = NULL;
	newNode->right = NULL;
	
	return newNode;
}

Node *push(struct Node *root, int val){
	if(!root){
		return makeNode(val);
	}else if(root->val > val){
		root->left = push(root->left, val);
	}else if(root->val < val){
		root->right = push(root->right, val);
	}else if(root->val==val){
		puts("Exist");
		return root;
	}
}

Node* search(Node *root, int val){
	if(!root){
		puts("Not Found");
		return NULL;
	}else if(root->val > val){
		return search(root->left, val);
	}else if(root->val < val){
		return search(root->right, val);
	}else{
		puts("Found");
	}
	return root;
}

Node *predeces(Node *root){
	while(root){
		if(root->right == NULL){
			return root;
		}
		root = root->right;
	}
	return NULL;
}

Node *del(Node *root, int val){
	if(!root){
		puts("Root Not Found");
		return root;
	}else if(val < root->val){
		root->left = del(root->left, val);
		return root;
	}else if(val > root->val){
		root->right = del(root->right, val);
		return root;
	}else{
		if(root->left == NULL && root->right == NULL){
			free(root);
			return NULL;
		}else if(root->left != NULL && root->right != NULL){
			Node *prede = predeces(root->left);
			root->val = prede->val;
			prede->val = val;
			root->left = del(root->left, val);
			return root;
		}else{
			Node *temp = root->left != NULL ? root->left : root->right;
			free(root);
			return temp;
		}
	}
}

void inorder(Node *root){
	if(!root){
		return;
	}
	inorder(root->left);
	printf("%d ", root->val);
	inorder(root->right);
}

void preorder(Node *root){
	if(!root){
		return;
	}
	printf("%d ", root->val);
	preorder(root->left);
	preorder(root->right);
}

void postorder(Node *root){
	if(!root){
		return;
	}
	postorder(root->left);
	postorder(root->right);
	printf("%d ", root->val);
}

int main()
{
	root = push(root, 8);
	push(root, 10);
	push(root, 5);
	push(root, 6);
	push(root, 15);
	
	inorder(root);
	del(root, 5);
	del(root, 11);
	inorder(root);
	
	return 0;
}
