#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>

struct Node{
	int val;
	Node *right, *left;
} *root = NULL;

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->val = val;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

Node *push(Node *curr, int val){
	if(!curr){
		return makeNode(val);
	}else if(curr->val > val){
		curr->left = push(curr->left, val);
	}else if(curr->val == val){
		puts("Data Exist");
	}else{
		curr->right = push(curr->right, val);
	}
	return curr;
}

void search(Node *curr, int val){
	if(!curr){
		puts("not exist");
	}else if(curr->val > val){
		search(curr->left, val);
	}else if(curr->val < val){
		search(curr->right, val);
	}else{
		puts("data found");
	}
	return;
}

//left once and then right
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
		puts("root not found");
		return root;
	}else if(val < root->val){
		root->left = deleteNode(root->left, val);
		return root;
	}else if(val > root->val){
		root->right = deleteNode(root->right, val);
		return root;
	}else{ //equal
		//case 1 : no child
//		if(root->left == NULL && root->right == NULL){
//			free(root);
//			return NULL;
//		}else if(root->left != NULL && root->right == NULL){ //case 2: 1 child
//			Node *temp = root->left;
//			free(root);
//			return temp;
//		}else if(root->right != NULL && root->left == NULL){
//			Node *temp = root->right;
//			free(root);
//			return temp;
//		}else{ //case 3 : both have children
//			Node *replacement = predecessor(root);
//			root->val = replacement->val;
//			replacement->val = val;
//			root->left = deleteNode(root->left, val);
//			return root;
//		}
//	}

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
}

Node *deleteAll(Node *root){
	if(root == NULL){
		return NULL;
	}
	deleteAll(root->left);
	deleteAll(root->right);
	free(root);
	return NULL;
}

Node *updateNode(Node *root, int oldVal, int newVal){
	root = deleteNode(root, oldVal);
	return push(root, newVal);
}

void inorder(Node *curr){
	if(!curr){
		return;
	}
	inorder(curr->left);
	printf("%d ", curr->val);
	inorder(curr->right);
}

void postorder(Node *curr){
	if(!curr){
		return;
	}
	postorder(curr->left);
	postorder(curr->right);
	printf("%d ", curr->val);
}

void preorder(Node *curr){
	if(!curr){
		return;
	}
	printf("%d ", curr->val);
	preorder(curr->left);
	preorder(curr->right);
}

void inorderindented(Node *curr, int count){
	if(!curr){
		return;
	}
	inorderindented(curr->right, count+1);
	for(int i=0; i<count; i++){
		printf("\t");
	}
	printf("%d\n", curr->val);
	inorderindented(curr->left, count+1);
}

int main()
{
//	struct Node *root = NULL;
	
	root = push(root, 50);
	root = push(root, 70);
	root = push(root, 20);
	root = push(root, 10);
	root = push(root, 30);
	root = push(root, 80);
//	root = push(root, 90);
	
	puts("inorder:");
	inorder(root);
	
	puts("");
	puts("preorder");
	preorder(root);
	
	puts("");
	puts("postorder");
	postorder(root);
	
	puts("");
	search(root, 10);
	search(root, 12);
	search(root, 1);
	search(root, 4);
	
	deleteNode(root, 50);
	updateNode(root, 80, 100);
	inorderindented(root, 0);
	
	root = deleteAll(root);
	
	inorder(root);
	
	return 0;
}
