#include<stdlib.h>
#include<stdio.h>

struct Node{
	int value, height, bf;
	Node *left, *right;
};

int max(int a, int b){
	return (a>b) ? a : b;
}

int getHeight(Node *root){
	return root ? root->height : 0;
}

int setBalanceFactor(Node *root){
	return getHeight(root->left) - getHeight(root->right);
}

int setHeight(Node *root){
	return max(getHeight(root->left), getHeight(root->right)) + 1;
}

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->height = 1;
	newNode->bf = 0;
	newNode->left = newNode->right = NULL;
	return newNode;
}

Node *updateNode(Node *root){
	root->height = setHeight(root);
	root->bf = setBalanceFactor(root);
	return root;
}

Node *leftRotate(Node *root){
	Node *pivot = root->right;
	Node *temp = pivot->left;
	pivot->left = root;
	root->right = temp;
	root = updateNode(root);
	pivot = updateNode(pivot);
	return root;
}

Node *rightRotate(Node *root){
	Node *pivot = root->left;
	Node *temp = pivot->right;
	pivot->right = root;
	root->left = temp;
	root = updateNode(root);
	pivot = updateNode(root);
	return root;
}

Node *rotation(Node *root){
	if(root->bf > 1){ //unbalanced left child
		if(root->left->bf >= 0){ // right rotate != zigzag
			return rightRotate(root);
		}else{ //left-right rotate = zigzag
			root->left = (root);
			return rightRotate(root);
		}
	}else if(root->bf < -1){ //unbalaced right child
		if(root->right->bf <= 0){ //left rotate != zigzag
			return leftRotate(root);
		}else{ //right-left rotate = zigzag
			root->right = rightRotate(root);
			return leftRotate(root);
		}
	}
	return root;
}

Node *insertNode(Node *root, int value){
	if(!root){
	    return createNode(value);
	}else if(value < root->value){
	    root->left = insertNode(root->left, value);
	}else if(value > root->value){
		root->right = insertNode(root->right, value);
	}
	return rotation(updateNode(root));
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

Node *deleteNode(Node *root, int value)
{
  if (!root)
  {
    return root;
  }
  else if (value < root->value)
  {
    root->left = deleteNode(root->left, value);
  }
  else if (value > root->value)
  {
    root->right = deleteNode(root->right, value);
  }
  else
  {
    if (!root->left || !root->right)
    {
      Node *newRoot = root->left ? root->left : root->right;
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

void inOrder(Node *root){
	if(root){
		inOrder(root->left);
	    printf("| %-3d | %4d   | %7d        |\n", root->value, root->height, root->bf);
	    inOrder(root->right);
	}
}

int main()
{
	Node *baseRoot = NULL;
  	int toInsert[] = {10, 11, 12, 5, 3, 2, 8, 7, 4};

  	for(int i = 0; i < 9; i++){
	    baseRoot = insertNode(baseRoot, toInsert[i]);
	    printf("\nAdded %d to the tree.\n", toInsert[i]);
	    printf("| %-3s | %-5s | %-14s |\n", "Key", "Height", "Balance Factor");
	    inOrder(baseRoot);
	    getchar();
 	}

  	for(int i = 0; i < 9; i++){
	    baseRoot = deleteNode(baseRoot, toInsert[i]);
	    printf("\nRemoved %d from the tree.\n", toInsert[i]);
	    printf("| %-3s | %-5s | %-14s |\n", "Key", "Height", "Balance Factor");
	    inOrder(baseRoot);
	    getchar();
	}
	return 0;
}
