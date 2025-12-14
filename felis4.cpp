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
    struct Node *pivot = tempNode->right;
    tempNode->right = pivot->left;

    if(pivot->left != NULL){
        pivot->left->parent = tempNode;
    }
    
    pivot->parent = tempNode->parent;

    if(tempNode->parent == NULL){
        root = pivot;
    }
    else if(tempNode == tempNode->parent->left){
        tempNode->parent->left = pivot;
    }
    else{
        tempNode->parent->right = pivot;
    }
    
    pivot->left = tempNode;
    tempNode->parent = pivot;

    return root; 
}

struct Node *rightRotate(struct Node *tempNode, struct Node *root){
    struct Node *pivot = tempNode->left;
    tempNode->left = pivot->right;

    if(pivot->right != NULL){
        pivot->right->parent = tempNode;
    }
    
    pivot->parent = tempNode->parent;

    if(tempNode->parent == NULL){
        root = pivot;
    }
    else if(tempNode == tempNode->parent->left){
        tempNode->parent->left = pivot;
    }
    else{
        tempNode->parent->right = pivot;
    }
    
    pivot->right = tempNode;
    tempNode->parent = pivot;
    
    return root; 
}

struct Node *balancing(struct Node *tempNode, struct Node *root){
    while(tempNode != root && tempNode->color != 'B' && tempNode->parent->color == 'R'){
        struct Node *parentNode = tempNode->parent;
     struct Node *grandparent = parentNode->parent;

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
        printf("%d(%c) ", root->number, root->color);
        inOrder(root->right);
    }
}

int main(){
 int input[] = {41, 22, 5, 51, 48, 29, 18, 21, 45, 3, 100, 20, 65, 80, 76, 21};

    for (int i = 0; i < 16; i++){
        root = insertion(root, input[i], NULL);
        puts("1");
        root = searching(root, input[i]);
    }

 inOrder(root);
 
 return 0;
}
