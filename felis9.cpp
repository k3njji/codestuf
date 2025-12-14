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
     struct Node *temp = createNewNode(number);
      if(parent != NULL){
   temp->parent = parent;
   }
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
        printf("%d ", root->number);
        inOrder(root->right);
    }
}

void print(Node *root, int level){
    if (root == NULL) return;
    print(root->right, level + 1);
    for(int i=0; i<level; i++) {
        printf("    ");
	}
    printf("%d", root->number);
    printf(" (%c)", root->color);
    puts("");
    print(root->left, level + 1);
}

int main(){
 int input[] = {41, 22, 5, 51, 48, 29, 18, 21, 45, 3, 100, 110, 78, 64, 1, 15, 12, 9, 17, 50};

    for (int i = 0; i < 20; i++){
        root = insertion(root, input[i], NULL);
        root = searching(root, input[i]);
    }

 printf("Inorder traversal of Created Tree\n");
  inOrder(root);
 puts("");
 print(root, 0);
 
  return 0;
}
