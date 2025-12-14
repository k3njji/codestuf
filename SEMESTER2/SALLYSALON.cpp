#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Node{
	int bf, height;
	char name[100];
	long long int price;
	char category[100];
	Node *left, *right;
	char avail[100];
} *root = NULL;

int apa = 0;

Node *createNode(char name[], char category[], long long int price, char avail[]){
	Node *newNode = (Node*)malloc(sizeof(Node));
	newNode->price = price;
	strcpy(newNode->avail, avail);
	strcpy(newNode->name, name);
	strcpy(newNode->category, category);
	newNode->left = newNode->right = NULL;
	newNode->height = 1;
	newNode->bf = 0;
	
//	printf("%s || %s || %lld || %s", newNode->name, newNode->category, newNode->price, newNode->avail);
	
	return newNode;
}

Node *updateNode(Node *curr){
	if(curr == NULL) return curr;
	
	int left = curr->left != NULL ? curr->left->height : 0;
	int right = curr->right != NULL ? curr->right->height : 0;
	
	curr->height = (left > right ? left : right) + 1;
	curr->bf = left - right;
	
	return curr;
}

Node *rightRotate(Node *curr){
	Node *newRoot = curr->left;
	Node *temp = newRoot->right;
	
	newRoot->right = curr;
	curr->left = temp;
	
	updateNode(curr);
	updateNode(newRoot);
	
	return newRoot;
}

Node *leftRotate(Node *curr){
	Node *newRoot = curr->right;
	Node *temp = newRoot->left;
	
	newRoot->left = curr;
	curr->right = temp;
	
	updateNode(curr);
	updateNode(newRoot);
	return newRoot;
}

Node *rotation(Node *curr){
	if(curr->bf >= 2){
		if(curr->left->bf <= -1){
			curr->left = leftRotate(curr->left);
		}
		return rightRotate(curr);
	}else if(curr->bf <= -2){
		if(curr->right->bf >= 1){
			curr->right = rightRotate(curr->right);
		}
		return leftRotate(curr);
	}
	return curr;
}

Node *insert(Node *curr, char name[], char category[], long long int price, char avail[]){
	if(curr == NULL){
		return createNode(name, category, price, avail);
	}else if(strcmp(curr->name, name) > 0){
		curr->left = insert(curr->left, name, category, price, avail);
	}else if(strcmp(curr->name, name) < 0){
		curr->right = insert(curr->right, name, category, price, avail);
	}else{
		puts("Duplicate");
	}
	updateNode(curr);
	return rotation(curr);
}

Node *prede(Node *curr){
	Node *temp = curr->left;
	while(temp->right != NULL){
		temp = temp->right;
	}
	return temp;
}

Node *del(Node *curr, char name[]){
	if(strcmp(curr->name, name) > 0){
		curr->left = del(curr->left, name);
	}else if(strcmp(curr->name, name) < 0){
		curr->right = del(curr->right, name);
	}else{
		apa = 1;
		if(!curr->left && !curr->right){
			free(curr);
			curr = NULL;
			return NULL;
		}else if(!curr->left || !curr->right){
			Node *temp = curr->left!=NULL ? curr->left : curr->right;
			free(curr);
			curr = NULL;
			return temp;
		}else{
			Node *temp = prede(curr);
			strcpy(curr->name, temp->name);
			strcpy(curr->avail, temp->avail);
			strcpy(curr->category, temp->category);
			curr->price = temp->price;
			curr->left = del(curr->left, temp->name);
		}
	}
	return rotation(updateNode(curr));
}

int sallyCheck(char name[]){
	char sally[100] = {"Sally"};
	for(int i = 0; i<5; i++){
		if(name[i] != sally[i]){
			return 0;
		}
	}
	return 1;
}

int wordCheck(char name[]){
	int count = 0;
	for(int i = 0; i<strlen(name); i++){
		if(name[i] == ' '){
			continue;
		}
		count++;
	}
	return count;
}

void validation(){
	puts("Insert New Treatment");
	
	char name[100];
	long long int price;
	char category[100], avail[100];
	int i = 0;
	int o = 0;
	do{
		printf("Input new treatment name: ");
		scanf("%[^\n]", &name); getchar();
		i = sallyCheck(name);
		o = wordCheck(name);
	}while(i==0 || strlen(name) >= 21 || strlen(name) <=4 || o <= 7);
	
	do{
		printf("Input treatment price [50000 - 1000000]: Rp");
		scanf("%lld", &price); getchar();
	}while(price<=49999 || price >= 999999);
	
	do{
		printf("Input treatment category[Hair Care | Nail Care | Body Care]: ");
		scanf("%[^\n]", &category); getchar();
	}while( (strcmp(category, "Hair Care")!=0) && (strcmp(category, "Nail Care")!=0) && (strcmp(category, "Body Care")!=0) );
	
	do{
		printf("Input treatment availability for home service [Available | Unavailable]: ");
		scanf("%[^\n]", &avail); getchar();
	}while( (strcmp(avail, "Available")!=0) && (strcmp(category, "Unavailable")!=0) );
	
	root = insert(root, name, category, price, avail);
}

void pre(Node *curr){
	if(curr == NULL) return;
	printf("%s || %s || %lld || %s\n", curr->name, curr->category, curr->price, curr->avail);
	pre(curr->left);
	pre(curr->right);
}

void in(Node *curr){
	if(curr == NULL) return;
	
	in(curr->left);
	printf("%s || %s || %lld || %s\n", curr->name, curr->category, curr->price, curr->avail);
	in(curr->right);
}

void post(Node *curr){
	if(curr == NULL) return;
	
	post(curr->left);
	post(curr->right);
	printf("%s || %s || %lld || %s\n", curr->name, curr->category, curr->price, curr->avail);
}

void view(){
	char view[100];
	do{
		printf("input view order [pre | in | post]: ");
		scanf("%[^\n]", view); getchar();
	}while( (strcmp(view, "pre")!=0) && (strcmp(view, "in")!=0) && (strcmp(view, "post")!=0) );
	puts("Treatment || Category || Price || Home Service");
	
	if(strcmp(view, "pre")==0){
		pre(root);
	}else if(strcmp(view, "in")==0){
		in(root);
	}else if(strcmp(view, "post")==0){
		post(root);
	}
}

void menu(){
	puts("Sally Salon");
	puts("Menu");
	puts("1. View Available Treatment");
	puts("2. Insert New Treatment");
	puts("3. Delete Treatment");
	puts("4. Exit");
	puts("[1-4]");
	printf(">> ");
}

int main()
{
	menu();
	int x;
	while(true){
		scanf("%d", &x); getchar();
		if(x==1){
			view();
		}else if(x==2){
			validation();
		}else if(x==3){
			char deleteItem[100];
			printf("Input treatment name to be deleted: ");
			scanf("%[^\n]", deleteItem); getchar();
			root = del(root, deleteItem);
			if(apa == 1){
				puts("[Delete Sucecssfully]");
			}else{
				puts("Data Not Found!");
			}
			apa = 0;
		}else if(x==4){
			puts("Thank You!");
			break;
		}
		printf("Press Enter to Continue"); getchar();
	}
	
	
	return 0;
}
