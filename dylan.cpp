#include<stdio.h>
#include<stdlib.h>

struct Node{
	int num, height, bf;
	Node *left, *right;
};
Node* createNode(int num){
	Node* newNode = (Node*)malloc(sizeof(Node));
	
	newNode->num = num;
	newNode->height = 1;
	newNode->left = newNode->right = NULL;
	
	return newNode;
}

int getHeight(Node* newNode){ //dapatin height dari node
	if(!newNode) return 0;
	else return newNode->height;
}

int getMax(int a, int b){ //ambil nilai max dari heightnya children
	if(a > b) return a;
	else return b;
}

int getBalancedFactor(Node* newNode){
	if(!newNode) return 0;
	
	return getHeight(newNode->left) - getHeight(newNode->right);
}

Node* leftRotation(Node* node){
	Node* right = node->right;
	Node* rightLeft = right->left;
	
	right->left = node;
	node->right = rightLeft;
	
	node->height = getMax(getHeight(node->left), getHeight(node->right) + 1);
	right->height = getMax(getHeight(right->left), getHeight(right->right) + 1);
	
	return right;
}

Node* rightRotation(Node* node){
	Node* left = node->left;
	Node* leftRight = left->right;
	
	left->right = node;
	node->left = leftRight;
	
	node->height = getMax(getHeight(node->left), getHeight(node->right) + 1);
	left->height = getMax(getHeight(left->left), getHeight(left->right) + 1);
	
	return left;
}

Node* insertNode(Node* root, int value){
	if(!root) return createNode(value);
	if(value < root->num) root->left = insertNode(root->left, value);
	else if(value > root->num) root->right = insertNode(root->right, value);
	else return root;
	
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	root->height = getMax(leftHeight, rightHeight)+1; //height dari rootnya
	
	int bf = getBalancedFactor(root);
	
	//Left Rotation
	if(bf < -1 && getBalancedFactor(root->right) <= 0){
		return leftRotation(root);
	}
	
	//left-Right Rotation
	else if(bf > 1 && getBalancedFactor(root->left) < 0){
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	
	//Right Rotation
	else if(bf > 1 && getBalancedFactor(root->left) >= 0){
		return rightRotation(root);
	}
	
	//Right-Left Rotation
	else if(bf < -1 && getBalancedFactor(root->right) > 0){
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}	
	
	return root;
}

Node* popNode(Node* root, int num){
	if(!root){
		printf("Not found\n");
		return root;
	}
	else if(num < root->num) root->left = popNode(root->left, num);
	else if(num > root->num) root->right = popNode(root->right, num);
	else if(num == root->num){
		//tidak punya anak
		if(!root->left && !root->right){
			free(root);
			root = NULL;
		}
		else if(root->left && !root->right){
			Node *temp = root->left;
			free(root);
			root = temp;
		}
		else if(!root->left && root->right){
			Node *temp = root->right;
			free(root);
			root = temp;
		}
		else if(root->left && root->right){
			Node* temp = root->left;
			
			while(temp->right){
				temp = temp->right;
			}
			
			root->num = temp->num;
			
			root->left = popNode(root->left, temp->num);
		}
	}
	
	if(!root) return root;
	
	int leftHeight = getHeight(root->left);
	int rightHeight = getHeight(root->right);
	root->height = getMax(leftHeight, rightHeight)+1; //height dari rootnya
	
	int bf = getBalancedFactor(root);
	
	//Left Rotation
	if(bf < -1 && getBalancedFactor(root->right) <= 0){
		return leftRotation(root);
	}
	
	//left-Right Rotation
	else if(bf > 1 && getBalancedFactor(root->left < 0)){
		root->left = leftRotation(root->left);
		return rightRotation(root);
	}
	
	//Right Rotation
	else if(bf > 1 && getBalancedFactor(root->left) >= 0){
		return rightRotation(root);
	}
	
	//Right-Left Rotation
	else if(bf < -1 && getBalancedFactor(root->right) > 0){
		root->right = rightRotation(root->right);
		return leftRotation(root);
	}	
	
	return root;
}

bool searchNode(Node* root, int num){
	if(!root){
		printf("Not found\n");
		return false;
	}
	else{
		printf("%d found\n", root->num);
		return true;
	}
	
	if(num < root->num) return searchNode(root->left, num);
	else if(num > root->num) return searchNode(root->right, num);
}

void printInOrder(Node* node){
	if(node){
		printInOrder(node->left);
		printf("%d ",node->num);
		printInOrder(node->right);
	}
}

void printPostOrder(Node* node){
	if(node){
		printPostOrder(node->left);
		printPostOrder(node->right);
		printf("%d ",node->num);
	}
}

void printPreOrder(Node* node){
	if(node){
		printf("%d ",node->num);
		printPreOrder(node->left);
		printPreOrder(node->right);
	}
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
			root = insertNode(root, value);
		}else if(choice == 2){
			printf("Delete: ");
			scanf("%d", &value); getchar();
			root = popNode(root, value);
//			if(index == 1){
//				puts("Data Found");
//				printf("Value %d is Deleted", value);
//			}else{
//				puts("Not Found");
//			}
//			index = 0;
		}else if(choice == 3){
			printf("Preorder: "); printPreOrder(root);
			printf("\nInorder: "); printInOrder(root);
			printf("\nPostorder: "); printPostOrder(root);
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
