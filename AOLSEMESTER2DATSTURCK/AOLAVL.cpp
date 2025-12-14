#include<stdio.h>
#include<stdlib.h>

struct Node{
	int value, height, bf;
	Node *left, *right;
};
int index = 0;

Node *update(Node *curr){
	if(curr==NULL) return NULL;
	
	int left = curr->left != NULL ? curr->left->height : 0;
	int right = curr->right != NULL ? curr->right->height : 0;
	
	curr->height = (left > right ? left : right) + 1;
	curr->bf = left - right;
	return curr;	
}

Node *leftRotate(Node *curr){
	if(curr == NULL) return NULL;
	
	Node *newRoot = curr->right;
	Node *temp = newRoot->left;
	newRoot->left = curr;
	curr->right = temp;
	update(curr);
	update(newRoot);
	return newRoot;
}

Node *rightRotate(Node *curr){
	if(curr == NULL) return NULL;
	
	Node *newRoot = curr->left;
	Node *temp = newRoot->right;
	newRoot->right = curr;
	curr->left = temp;
	update(curr);
	update(newRoot);
	return newRoot;
}

Node *rotate(Node *curr){
	if(curr == NULL) return NULL;
	
	if(curr->bf <= -2){
		if(curr->right->bf >= 1){
			curr->right = rightRotate(curr->right);
		}
		return leftRotate(curr);
	}else if(curr->bf >= 2){
		if(curr->left->bf <= -1){
			curr->left = leftRotate(curr->left);
		}
		return rightRotate(curr);
	}
	return curr;
}

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->left = newNode->right = NULL;
	newNode->value = value;
	newNode->height = 1;
	newNode->bf = 0;
	return newNode;
}

Node *insert(Node *curr, int value){
	if(curr == NULL){
		puts("Added!");
		return createNode(value);
	}else if(curr->value < value){
		curr->right = insert(curr->right, value);
	}else if(curr->value == value){
		puts("Duplicate");
	}else{
		curr->left = insert(curr->left, value);
	}
	update(curr);
	return rotate(curr);
}

Node *pred(Node *curr){
	Node *temp = curr->left;
	while(temp->right){
		temp = temp->right;
	}
	return temp;
}

Node *del(Node *curr, int value){
	if(curr == NULL) return NULL;
	
	if(curr->value > value){
		curr->left = del(curr->left, value);
	}else if(curr->value < value){
		curr->right = del(curr->right, value);
	}else{
		index = 1;
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
			return NULL;
		}else if(!curr->left || !curr->right){
			Node *temp = !curr->left ? curr->right : curr->left;
			free(curr);
			curr = NULL;
			return temp;
		}else{
			Node *temp = pred(curr);
			curr->value = temp->value;
			curr->left = del(curr->left, temp->value);
		}
	}
	return rotate(update(curr));
}

void print(Node *root, int level){
    if (root == NULL) return;
    print(root->right, level + 1);
    for(int i=0; i<level; i++) {
        printf("    ");
	}
    printf("|-- %d\n", root->value);
    print(root->left, level + 1);
}

void inOrder(Node *curr){
	if(curr == NULL) return;
	
	inOrder(curr->left);
	printf("%d ", curr->value, curr->height, curr->bf);
	inOrder(curr->right);
}

void postOrder(Node *curr){
	if(curr == NULL) return;
	
	postOrder(curr->left);
	postOrder(curr->right);
	printf("%d ", curr->value);
}

void preOrder(Node *curr){
	if(curr == NULL) return;
	
	printf("%d ", curr->value);
	preOrder(curr->left);
	preOrder(curr->right);
}

void menu(){
	puts("1. Insertion");
	puts("2. Deletion");
	puts("3. Transversal");
	puts("4. Exit");
	printf("Choose: ");
}

int main()
{
	Node *root = NULL;
	while(true){
		system("cls");
		menu();
		int choice, value;
		scanf("%d", &choice); getchar();
		if(choice==1){
			printf("Insert: ");
			scanf("%d", &value); getchar();
			root = insert(root, value);
		}else if(choice == 2){
			printf("Delete: ");
			scanf("%d", &value); getchar();
			root = del(root, value);
			if(index == 1){
				puts("Data Found");
				printf("Value %d is Deleted", value);
			}else{
				puts("Not Found");
			}
			index = 0;
		}else if(choice == 3){
			printf("Preorder: "); preOrder(root);
			printf("\nInorder: "); inOrder(root);
			printf("\nPostorder: "); postOrder(root);
			puts("");
		}else if(choice == 4){
			printf("Thank You!");
			break;
		}
		printf("Press Enter to Continue! ");
		getchar();
	}
	return 0;
}
