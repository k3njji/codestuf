#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value, color;
	struct Node *parent, *left, *right;
} *root = NULL;

int check = 0;

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->color = 1; // 0 is black, 1 is red
	newNode->parent = newNode->right = newNode->left = NULL;
	return newNode;
}

Node *rightRotate(Node *newNode, Node *root){
	Node *pivot = newNode->left;
    newNode->left = pivot->right;
    if(pivot->right != NULL){
        pivot->right->parent = newNode;
    }
    
    pivot->parent = newNode->parent;
    if(newNode->parent == NULL){
        root = pivot;
    }else if(newNode == newNode->parent->left){
        newNode->parent->left = pivot;
    }else{
        newNode->parent->right = pivot;
	}
	
    pivot->right = newNode;
    newNode->parent = pivot;
    return root;
}

Node *leftRotate(Node *newNode, Node *root) {
    Node *pivot = newNode->right;
    newNode->right = pivot->left;
    if(pivot->left != NULL){
        pivot->left->parent = newNode;
    }

    pivot->parent = newNode->parent;
    if(newNode->parent == NULL){
        root = pivot;
    }else if(newNode == newNode->parent->left){
        newNode->parent->left = pivot;
    }else{
        newNode->parent->right = pivot;
    }

    pivot->left = newNode;
    newNode->parent = pivot;
    return root;
}

Node *balance(Node *root, Node *newNode){
    while(newNode!=root && newNode->color != 0 && newNode->parent->color == 1){
    	Node *parent = newNode->parent;
    	Node *grandpa = parent->parent;
    	
    	if(parent == grandpa->left){
    		Node *uncle = grandpa->right;
    		if(uncle != NULL && uncle->color == 1){
    			grandpa->color = 1;
    			uncle->color = parent->color = 0;
    			newNode = grandpa;
			}else{
				if(newNode == parent->right){
					root = leftRotate(parent, root);
					newNode = parent;
					parent = newNode->parent;
				}
				root = rightRotate(grandpa, root);
				grandpa->color = 1;
				parent->color = 0;
			}
		}else{
			Node *uncle = grandpa->left;
			if(uncle != NULL && uncle->color == 1){
				grandpa->color = 1;
    			uncle->color = parent->color = 0;
    			newNode = grandpa;
			}else{
				if(newNode == parent->left){
					root = rightRotate(parent, root);
					newNode = parent;
					parent = newNode->parent;
				}
				root = leftRotate(grandpa, root);
				grandpa->color = 1;
				parent->color = 0;
			}
		}
	}
	root->color = 0;
	return root;
}

Node *insert(Node *curr, Node *parent, Node *newNode){
	if (curr == NULL){
		newNode->parent = parent;
		if(newNode->parent==NULL)  newNode->color = 0;
		return newNode;
	}else if (curr->value > newNode->value){
		curr->left = insert(curr->left, curr, newNode);
	}else if (curr->value == newNode->value){
		printf("Duplicate!");
		free(newNode);
		check = 1;
	}else{
		curr->right = insert(curr->right, curr, newNode);
	}
	return curr;
}

void print(Node *root, int level){
    if (root == NULL) return;
    print(root->right, level + 1);
    for(int i=0; i<level; i++) {
        printf("    ");
	}
    printf("%d", root->value);
    printf(" (%d)", root->color);
    puts("");
    print(root->left, level + 1);
}

void inOrder(Node *root){
	if(root == NULL) return;
	
	inOrder(root->left);
	printf("%d(%d) ", root->value, root->color);
	inOrder(root->right);
}

int main()
{
	int value[] = {41, 22, 5, 51, 48, 29, 18, 21, 45, 3};
    for (int i=0; i<10; i++){
    	Node *newNode = createNode(value[i]);
        root = insert(root, NULL, newNode);
        if(check == 0) root = balance(root, newNode);
    }
//	print(root, 0);
	printf("Inorder Transveral of Created Tree: \n");
	puts("(0) is Black (1) is Red");
	inOrder(root);
	
	return 0;
}
