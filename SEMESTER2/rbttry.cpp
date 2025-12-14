#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value, color;
	Node *parent, *left, *right;
};

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->color = 1; // 0 is black, 1 is red
	newNode->parent = newNode->right = newNode->left = NULL;
	return newNode;
}


struct Node *rotateLeft(struct Node *root, struct Node *node) {
    struct Node *pivot = node->right;
    node->right = pivot->left;

    if (pivot->left != NULL) {
        pivot->left->parent = node;
    }

    pivot->parent = node->parent;

    if (node->parent == NULL) {
        root = pivot;
    } else if (node == node->parent->left) {
        node->parent->left = pivot;
    } else {
        node->parent->right = pivot;
    }

    pivot->left = node;
    node->parent = pivot;

    return root;
}

struct Node *rotateRight(struct Node *root, struct Node *node) {
    struct Node *pivot = node->left;
    node->left = pivot->right;

    if (pivot->right != NULL) {
        pivot->right->parent = node;
    }

    pivot->parent = node->parent;

    if (node->parent == NULL) {
        root = pivot;
    } else if (node == node->parent->right) {
        node->parent->right = pivot;
    } else {
        node->parent->left = pivot;
    }

    pivot->right = node;
    node->parent = pivot;

    return root;
}

void balance(struct Node *root, struct Node *newNode) {
   
}

Node *insert(Node *curr, Node *parent, int value, Node *akar){
	if(curr == NULL){
		Node *newNode = createNode(value);
		if(parent == NULL){
			newNode->color = 0;
		}
		newNode->parent = parent; // Corrected placement
		curr = newNode;
		balance(akar, newNode);
	}else if(curr->value > value){
		curr->left = insert(curr->left, curr, value, akar);
	}else if(curr->value == value){
		printf("Duplicate!");
	}else{
		curr->right = insert(curr->right, curr, value, akar);
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

int main()
{
	Node *root = NULL;
	int toInsert[] = {41, 22, 5, 51};
    for (int i = 0; i < 4; i++)
    {
        root = insert(root, NULL, toInsert[i], root);
    }
		print(root, 0);
	
	return 0;
}
