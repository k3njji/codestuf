#include<stdio.h>
#include<stdlib.h>

struct Node{
 int number;
 char color;
 struct Node *parent, *left, *right;
} *root = NULL;

struct Node *createNewNode(int number){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    temp->number = number;
    temp->color = 'R';
    temp->parent = NULL;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct Node *leftRotate(struct Node *tempNode, struct Node *root){
    struct Node *curr = tempNode->right;
    tempNode->right = curr->left;

    if(curr->left != NULL){
        curr->left->parent = tempNode;
    }
    
    curr->parent = tempNode->parent;

    if(tempNode->parent == NULL){
        root = curr;
    }
    else if(tempNode == tempNode->parent->left){
        tempNode->parent->left = curr;
    }
    else{
        tempNode->parent->right = curr;
    }
    
    curr->left = tempNode;
    tempNode->parent = curr;

    return root; 
}

struct Node *rightRotate(struct Node *tempNode, struct Node *root){
    struct Node *curr = tempNode->left;
    tempNode->left = curr->right;

    if(curr->right != NULL){
        curr->right->parent = tempNode;
    }
    
    curr->parent = tempNode->parent;

    if(tempNode->parent == NULL){
        root = curr;
    }
    else if(tempNode == tempNode->parent->left){
        tempNode->parent->left = curr;
    }
    else{
        tempNode->parent->right = curr;
    }
    
    curr->right = tempNode;
    tempNode->parent = curr;
    
    return root; 
}

struct Node *balancing(struct Node *tempNode, struct Node *root){
//    struct Node *parentNode = NULL, *grandparent = NULL;

    while(tempNode != root && tempNode->color != 'B' && tempNode->parent->color == 'R'){
        Node *parentNode = tempNode->parent;
    	Node *grandparent = parentNode->parent->parent;

        if(parentNode == grandparent->left){
            struct Node *uncleNode = grandparent->right;

            if(uncleNode != NULL && uncleNode->color == 'R'){
                grandparent->color = 'R';
                uncleNode->color = 'B';
                parentNode->color = 'B';
                tempNode = grandparent;
            }
            else{
                if(tempNode == parentNode->right){
                    root = leftRotate(parentNode, root);
                    tempNode = parentNode;
                    parentNode = tempNode->parent;
                }

                root = rightRotate(grandparent, root);
                grandparent->color = 'R';
                parentNode->color = 'B';
                tempNode = parentNode;
            }
        }
        else{
            struct Node *uncleNode = grandparent->left;

            if(uncleNode != NULL && uncleNode->color == 'R'){
                grandparent->color = 'R';
                uncleNode->color = 'B';
                parentNode->color = 'B';
                tempNode = grandparent;
            }
            else{
                if(tempNode == parentNode->left){
                    root = rightRotate(parentNode, root);
     tempNode = parentNode;
     parentNode = tempNode->parent;
                }

                root = leftRotate(grandparent, root);
    grandparent->color = 'R';
                parentNode->color = 'B';
                tempNode = parentNode;
            }
        }
    }

    root->color = 'B';

 return root;
}

struct Node *insertion(struct Node *root, int number, struct Node *parent){
    if(root == NULL){
    	Node *temp = createNewNode(number);
    	if(parent!=NULL) temp->parent = parent;
        return temp;
    }
    else if(number > root->number){
    	
        root->right = insertion(root->right, number, root);
    }
    else if(number < root->number){
        root->left = insertion(root->left, number, root);
    }
    else{
        printf("Duplicate Error!\n");
    }
    
    return root;
}

struct Node *searching(struct Node *temp, int number){
	puts("4");
    if(temp == NULL){
        return temp;
    }
    else if(number == temp->number){
        return balancing(temp, root);
    }
    else if(number < temp->number){
        return searching(temp->left, number);
    }
    else if(number > temp->number){
        return searching(temp->right, number);
    }

    return temp;
}

void inOrder(struct Node *root){
    if(root == NULL){
        return;
    }
    else{
        inOrder(root->left);
        printf("%d ", root->number);
        inOrder(root->right);
    }
}

int main(){
 int input[] = {41, 22, 5, 51, 48, 29, 18, 21, 45, 3};

    for (int i = 0; i < 10; i++){
        root = insertion(root, input[i], NULL);
        puts("1");
        root = searching(root, input[i]);
    }

 inOrder(root);
 
 return 0;
}
