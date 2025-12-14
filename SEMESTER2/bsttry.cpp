#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Node{
	int value;
	Node *left;
	Node *right;
};

Node *makeNode(int val){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = val;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

Node* push(Node *temp, int val){
    Node *parent = NULL;
    Node *curr = temp;

    Node *newNode = makeNode(val);
    while(curr != NULL){
        parent = curr;
        if(curr->value < val){
            curr = curr->right;
        }else if(curr->value > val){
            curr = curr->left;
        }else if(curr->value == val){
            return temp;
        }
    }
    curr = newNode;

    if(parent == NULL){
        temp = newNode;
    }else if(parent->value < val){
        parent->right = newNode;
    }else{
        parent->left = newNode;
    }

    return temp;
}

int search(Node *temp, int val){
	while(temp!=NULL){
		if(temp->value < val){
			temp = temp->right;
		}else if(temp->value > val){
			temp = temp->left;
		}else if(temp->value == val){
			return 1;
		}
	}
	return 0;
}

void inOrder(Node *curr) {
	if(curr != NULL) {
		inOrder(curr->left);
		printf("%d\n", curr->value);
		inOrder(curr->right);
	}
}

int main()
{
	Node *root = NULL;
	root = push(root, 17);
	push(root, 20);
	push(root, 15);
	push(root, 25);
	push(root, 1);
	inOrder(root);

	return 0;	
}
