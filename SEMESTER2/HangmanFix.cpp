#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>

struct Node{
	char name[11];
	Node *next, *prev;
} *head=NULL, *tail=NULL;

int check = 0;
int index = 0;
const int max = 5;

char correct[max][11]={NULL};
int corr=0;

Node* makeNode(char name[]){
	Node *newNode = (Node*)malloc(sizeof(Node));
	strcpy(newNode->name, name);
	newNode->next = NULL;
	newNode->prev = NULL;
	return newNode;
}

void push(char name[]){
	Node *newNode = makeNode(name);
	if(head==NULL){
		head = tail = newNode;
	}else{
		newNode->prev = tail;
		tail->next = newNode;
		tail = newNode;
	}
}

void pop(){
	if(!head) return;
	if(strcmp(correct[corr-1], head->name)==0){
		if(head==tail){
			free(head);
			head = tail = NULL;
		}else{
			Node *temp = head->next;
			temp->prev = NULL;
			free(head);
			head = temp;
		}
	}else if(strcmp(correct[corr-1], tail->name)==0){
		if(head==tail){
			free(head);
			head = tail = NULL;
		}else{
		Node *temp = tail->prev;
		tail->prev->next = NULL;
		tail->prev = NULL;
		free(tail);
		tail = temp;
		}
	}else{
		Node *curr = head;
		while(curr){
			if(strcmp(correct[corr-1], curr->name)==0){
				Node *temp = curr->next;
				temp->prev = curr->prev;
				curr->prev->next = temp;
				free(curr);
				return;
			}
			curr = curr->next;
		}
	}
}

void print(char val[], char a){
	Node *temp = head;
	puts("============");
	while(temp){
		int popers = 0;
		int len = strlen(temp->name);
		for(int i=0; i<len; i++){
			int cek = 0;
			if(a==temp->name[i]){
				check=1;
			}
			for(int j=0; j<index; j++){
				if(val[j] == temp->name[i]){
					cek=1;
					popers++;
					break;
				}
			}
			if(cek == 1){
				printf("%c", temp->name[i]);
			}else{
				printf("_");
			}
		}
		puts("");
		
		if(len == popers) strcpy(correct[corr++], temp->name);
		popers = 0;
		
		temp = temp->next;
	}
	puts("============");
}

void printCorr(){
	for(int i=0; i<corr; i++){
		printf("%s\n", correct[i]);
	}	
}

int main(){
	puts("HANGMAN");
    printf("Insert the Amount of Words (Minimum = 5): ");
    int x;
    scanf("%d", &x);
    while(x<5){
    	printf("Please Input the Amount of Words Again (Minimum = 5): ");
        scanf("%d", &x);
	}
	
    srand(time(NULL));

    char word[x+1][11];
    puts("Insert the Word (Word Length = 10):");
    for(int i=0; i<x; i++){
        scanf("%s", word[i]);
        getchar();
        int len = strlen(word[i]);
        while(len>10){
        	puts("Word Lenght is more than 10");
        	scanf("%s", word[i]);
      		getchar();
      		len = strlen(word[i]);
		}
    }
    
//    system("cls");

    int ran[max] = {-1};
    for(int i=0; i<max; i++){
        int temp = rand() % x;
        for(int j=0; j<i; j++){
            if(ran[j] == temp){
                temp = rand() % x;
                j = -1;
            }
        }
        ran[i] = temp;
    }
    
    for(int i=0; i<max; i++){
    	push(word[ran[i]]);
	}
	
	puts("HANGMAN STARTS");
	puts("Complete the Words");
	int counter=10;
	printf("You Have 10 Lives, Now Guess The Alphabets for the Words\n");
	char val[53]={NULL};
	while(counter!=0){
		if(index == 0) print(val, NULL);
		puts("Input The Alphabets (Case Sensitive)");
		char a;
		scanf("%c", &a); getchar();
		system("cls");
		
		int vali=0;
		for(int i=0; i<index; i++){
			if(a==val[i]){
				vali=1;
			}
		}
		if(vali == 0) val[index++] = a;
		else puts("The Alphabets Is Already Guessed");
		
		puts("Incomplete Words:");
		print(val, a);
		puts("");
		
		puts("Completed Words: ");
		puts("============");
		if(corr!=0){
		pop();
		printCorr();
		}
		puts("============");
		puts("");
		
		puts("Guessed Alphabets:");
		for(int i=0; i<index; i++){
		printf("%c ", val[i]);
		}
		printf("\n\n");
		
		if(check==0){
			counter--;
			printf("Wrong! You Have %d Lives Now\n\n", counter);
		}else{
			printf("You Still Have %d Lives\n\n", counter);
			check = 0;
		}
		
		if(head==NULL){
			puts("You Guess All The Words Correctly!");
			puts("Congratss");
			return 0;
		}
	}
	
	puts("You Lose");
	puts("The Rest of The Words are:");
	Node *temp = head;
	while(temp){
	printf("%s\n", temp->name);
	temp = temp->next;
	}

    return 0;
}

