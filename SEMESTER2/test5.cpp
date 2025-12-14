#include<stdlib.h>
#include<stdio.h>

struct Node{
	int value, bf, height;
	Node *left, *right;
} *root = NULL;

void print(Node *root, int level){
    if (root == NULL) return;
    print(root->right, level + 1);
    for(int i=0; i<level; i++){
        printf("          ");
	}
    printf("|- %d(%d, %d)\n", root->value, root->height, root->bf);
    print(root->left, level + 1);
}

void printCantik(Node *root){
	puts("=================================================");
	puts("The Tree (Left to Right):");
	print(root, 0);
	puts("=================================================");
}

Node *createNode(int value){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->value = value;
	newNode->left = newNode->right = NULL;
	newNode->bf = 0;
	newNode->height = 1;
	return newNode;
}

Node *updateNode(Node *root){
	if(root == NULL) return NULL;
	int left = root->left != NULL ? root->left->height : 0;
	int right = root->right ? root->right->height : 0;
	root->height = (left > right ? left : right)+1;
	root->bf = left - right;
	return root;
}

Node *leftRotate(Node *oldRoot){
	if(oldRoot==NULL) return NULL;
	puts("Left Rotation");
	
	Node *newRoot = oldRoot->right;
	Node *temp = newRoot->left;
	
	newRoot->left = oldRoot;
	oldRoot->right = temp;
	updateNode(oldRoot);
	updateNode(newRoot);
	return newRoot;
}

Node *rightRotate(Node *oldRoot){
	if(oldRoot==NULL) return NULL;
	puts("Right Rotation");
	
	Node *newRoot = oldRoot->left;
	Node *temp = newRoot->right;
	
	newRoot->right = oldRoot;
	oldRoot->left = temp;
	
	updateNode(oldRoot);
	updateNode(newRoot);
	
	oldRoot = newRoot;
	return newRoot;
}

Node *rotation(Node *curr){
	if(curr==NULL) return NULL;
	int a = 0;
	if(curr->bf <= -2){
		a++;
		if(curr->right->bf >= 1){
			curr->right = rightRotate(curr->right);
			printCantik(root);
			printf("Press Enter to Continue..."); getchar();
		}
		curr = leftRotate(curr);
	}else if(curr->bf >= 2){
		a++;
		if(curr->left->bf <= -1){
			curr->left = leftRotate(curr->left);
			printCantik(root);
			printf("Press Enter to Continue..."); getchar();
		}
		curr = rightRotate(curr);	
	}
	if(a==0){
		puts("No Rotation");
	}
	return curr;
}

Node *insert(Node *curr, int value, int *c){
	if(curr==NULL){
		*c = 1;
		return createNode(value);
	}else if(curr->value < value){
		curr->right = insert(curr->right, value, c);
	}else if(curr->value > value){
		curr->left = insert(curr->left, value, c);
	}else{
		puts("Duplicate");
	}
	updateNode(curr);
	if(*c==1){
		printCantik(root);
		*c = 0;
	}
	return rotation(curr);
}

Node *predecessor(Node *curr){
	Node *temp = curr->left;
	while(temp->right){
		temp = temp->right;
	}
	return temp;
}

Node *removeNode(Node *curr, int value){
	if(curr == NULL) return curr;
	int printed = 0;
	if(value < curr->value) curr->left = removeNode(curr->left, value);
	else if(value > curr->value) curr->right = removeNode(curr->right, value);
	else{
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
			printed=1;
			return NULL;
		}else if(!curr->left || !curr->right){
			Node *temp = (!curr->left) ? curr->right : curr->left;
			free(curr);
			curr = NULL;
			printed = 1;
			return temp;
		}else{
			Node *temp = predecessor(curr);
			curr->value = temp->value;
			curr->left = removeNode(curr->left, temp->value);
		}
	}
	if(printed != 0) printCantik(root); getchar();
	return rotation(updateNode(curr));
}

	void search(Node *curr, int value){
		if(curr == NULL){
			printf("Number Doesnt Exist\n");
			return;
		}else if(root->value < value){
			search(curr->right, value);
		}else if(curr->value == value){
			printf("%d Exist\n", value);
		}else{
			search(curr->left, value);
		}
		return;
	}

void menu(){
	puts("AVL Simulator");
	puts("Press the number to continue");
	puts("1. Insert Nodes");
	puts("2. Delete Nodes");
	puts("3. Search Nodes");
}

int main()
{
	while(true){
		system("cls");
		printCantik(root);
		menu();
		int a, b, c;
		scanf("%d", &a); getchar();
		if(a==1){
			c = 0;
			scanf("%d", &b); getchar();
			root = insert(root, b, &c);
			printCantik(root);
		}else if(a==2){
			scanf("%d", &b); getchar();
			root = removeNode(root, b);
			printCantik(root);
		}else if(a==3){
			scanf("%d", &b); getchar();
			search(root, b);
		}
		printf("Press Enter to Continue..."); getchar();
	}
	
	return 0;
}
