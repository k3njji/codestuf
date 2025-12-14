#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<time.h>
#include<ctype.h>
#define SIZE 1007 

struct Node{
    char BookID[50];
    char BookTitle[50];
    char BookAuthor[50];
    char ISBN[15];
    int pageNumber;
    struct Node *next;
} *table[SIZE] = {NULL};

struct Node *createNewNode(char bookID[], char bookTitle[]){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    strcpy(temp->BookID, bookID);
    strcpy(temp->BookTitle, bookTitle);
    temp->next = NULL;
}

void mainMenu(){
    puts("Bluejack Library");
    puts("=================");
    puts("1. View Book");
    puts("2. Insert Book");
    puts("3. Remove Book");
    puts("4. Exit");
}

int hashFunction(char bookID[]){
    int lenBookID = strlen(bookID);
    int key = 0;

    for(int i = 0; i < lenBookID; i++){
        key += bookID[i];
    }

    return key % SIZE;
}

// void push(char bookID[], char bookTitle[]){
//     int key = hashFunction(bookID);
//     struct Node *temp = createNewNode(bookID, bookTitle);

//     if(table[key] == NULL){

//     }
// }

void view(){

}

int searching(char bookTitle[]){
    for(int i = 0; i < SIZE; i++){
        if(table[i] != NULL){
            struct Node *curr =  table[i];

            while(curr != NULL){
                if(strcmp(curr->BookTitle, bookTitle) == 0){
                    return 1;
                }

                curr = curr->next;
            }  
        }
        
    }

    return 0;
}

void insert(){
    char tempBookTitle[100];
    char tempBookAuthor[100];
    char tempISBN[15];
    int tempPageNumber;

    // book title validation
    printf("Input book title [5-50][unique]: ");
    scanf("%[^\n]", tempBookTitle); getchar();
    int len = strlen(tempBookTitle); 
    int validate = searching(tempBookTitle);
    printf("%d\n", validate);

    while((len < 5 || len > 50) && validate == 1){
        printf("The book title is already exists !\n");
        printf("Input book title [5-50][unique]: ");
        scanf("%[^\n]", tempBookTitle); getchar();

        len = strlen(tempBookTitle); 
        validate = searching(tempBookTitle);
        // printf("%d\n", validate);
    }
    
    int checkBA;
    int lenBA;

    // book author validation
    do{
        checkBA = 0;

        printf("Input author name[3-25][Mr. | Mrs. ]: ");
        scanf("%[^\n]", tempBookAuthor); 

        lenBA = strlen(tempBookAuthor);

        if(tempBookAuthor[0] == 'M' && tempBookAuthor[1] == 'r' && tempBookAuthor[2] == 's' && tempBookAuthor[3] == '.'){
            checkBA = 1;
        }

        if(tempBookAuthor[0] == 'M' && tempBookAuthor[1] == 'r' && tempBookAuthor[2] == '.'){
            checkBA = 1;
        }
    } while(checkBA == 0 || (lenBA < 3 || lenBA > 25));

    // isbn validation
    // do
    // {
        
    // } while ();2

    



    // push(tempBookTitle);
}

void remove(){
    
}

int main(){
    int choice;

    do{
        mainMenu();
        printf(">> ");
        scanf("%d", &choice); getchar();

        switch(choice){
            case 1:
                view();
                break;
            case 2:
                insert();
                break;
            case 3:
                remove();
                break;
        }
    }while(choice != 4);


    return 0;
}
