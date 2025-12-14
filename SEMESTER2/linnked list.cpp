#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct data{
	char name[30];
	int age;
};

struct Node{
//	char name[30];
//	int age;
	struct data dat;
	struct Node *next;
}*head = NULL, *tail = NULL;

struct Node *createNode (struct data dataInput){
	struct Node *newNode = (struct Node*)malloc(sizeof(struct Node));
//	strcpy (newNode->name, name);
//	newNode->age = age;
	newNode->dat = dataInput;
	newNode->next = NULL;
	return newNode;
}

void pushHead(struct data dataInput){
	if (head == NULL){
		struct Node *insertNode = createNode(dataInput);
		head = insertNode;
		tail = insertNode;
	}
	else{
		struct Node *insertNode = createNode(dataInput);
		insertNode->next = head;
		head = insertNode;
	}
}

void pushTail(struct data dataInput){
	if (head == NULL){
		struct Node *insertNode = createNode(dataInput);
		head = insertNode;
		tail = insertNode;
	}
	else{
		struct Node *insertNode = createNode(dataInput);
		tail->next = insertNode;
		tail = tail->next;
	}
}

void pushMid(struct data dataInput){
	if (head == NULL){
		pushHead(dataInput);
	}
	else if (dataInput.age <= head->dat.age){
		pushHead(dataInput);
	}
	else if (dataInput.age >= tail->dat.age){
		pushTail(dataInput);
	}
	else{
		struct Node *curr = head;
		while (curr->next != NULL && dataInput.age >= curr->next->dat.age){
			curr = curr->next;
		}
		struct Node *insertNode = createNode(dataInput);
		struct Node *beforeInsert = curr;
		struct Node *afterInsert = curr->next;
		beforeInsert->next = insertNode;
		insertNode->next = afterInsert;
	}
	// else dan else if nya untuk sorting data berdasarkan agenya
}

void printNodes(){
	struct Node *curr = head;
	while (curr!=NULL){
		printf("|%s-%d| -> ", curr->dat.name, curr->dat.age);
		curr = curr->next;
	}
	printf("NULL\n");
}

//search data berdasarkan nama
void searchData(char searchKey[]){
	struct Node *curr = head;
	while (curr != NULL && strcmp(curr->dat.name, searchKey) != 0){
		curr = curr->next;
	}
	if (curr != NULL && strcmp(curr->dat.name, searchKey) == 0){
		printf("Data %s found\n", searchKey);
	}
	else{
		printf("Data %s not found\n", searchKey);
	}
}

void popHead(){
	if(head == NULL){
		return;
	}
	struct Node *toDelete = head;
	head = head->next;
	free(toDelete);
	//free = function untuk release datanya / delete datanya
}

void popTail(){
	if(head == NULL){
		return;
	}
	struct Node *curr = head;
	while (curr->next != tail){
		curr = curr->next;
	}
	struct Node *toDelete = curr->next;
	tail = curr;
	tail->next = NULL;
	free (toDelete);
//	atau bisa seperti ini untuk free nya
//	free(curr->next);

	//free = function untuk release datanya / delete datanya
}

void popMid(char popKey[]){
	if (head == NULL){
		return;
	}
	// jika nama yang mau dihapus berada di head
	else if (strcmp(head->dat.name, popKey) == 0){
		popHead();
	}
	else{
		struct Node *curr = head;
		while (curr->next != NULL && strcmp(curr->next->dat.name, popKey) != 0){
			curr = curr->next;
		}
		if (curr->next != NULL && strcmp(curr->next->dat.name, popKey) == 0){
			struct Node *toDelete = curr->next;
			struct Node *beforeDelete = curr;
			struct Node *afterDelete = toDelete->next;
			beforeDelete->next = afterDelete;
			free(toDelete);
		}
		else{
			printf("Data %s not found\n", popKey);
		}
	}
}

int main(){
	struct data dataInput;
	scanf("%[^,],%d", dataInput.name, &dataInput.age); getchar();
	pushMid(dataInput);
	printNodes();
	
	scanf("%[^,],%d", dataInput.name, &dataInput.age); getchar();
	pushMid(dataInput);
	printNodes();
	
	scanf("%[^,],%d", dataInput.name, &dataInput.age); getchar();
	pushMid(dataInput);
	printNodes();
	
	scanf("%[^,],%d", dataInput.name, &dataInput.age); getchar();
	pushMid(dataInput);
	printNodes();
	
	popHead();
	printNodes();
	system("pause");
	
	popTail();
	printNodes();
	system("pause");
	
	popMid("Daniel");
	printNodes();
	system("pause");
	
	return 0;
} 
