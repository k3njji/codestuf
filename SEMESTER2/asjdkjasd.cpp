#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char stakeholder[][10]={"Lecturer", "Student"};
bool isShow = false;

struct node{
    int binusianID;
    char binusianName[26];
    char type[15];
    struct node *left;
    struct node *right;
}*root = NULL, *curr;

struct node *newNode(int binusianID, char *binusianName, char *type){
    curr = (struct node *) malloc (sizeof(struct node));
    curr->binusianID = binusianID;
    strcpy(curr->binusianName, binusianName);
    strcpy(curr->type, type);
    curr->left = NULL;
    curr->right = NULL;
    return curr;
}

struct node *insert(struct node *ptr, int binusianID, char *binusianName, char *type){
 // insert code here

 if(ptr == NULL){
        return newNode(binusianID, binusianName, type);
    }
    else if(ptr->binusianID < binusianID){
        root->right = insert(root->right, binusianID, binusianName, type);
    }
    else if(ptr->binusianID > binusianID){
        root->left = insert(root->left, binusianID, binusianName, type);
    }
    else{
        printf("Duplicate Error!\n");
    }

    return ptr;
}

struct node *removeAll(struct node *ptr){
 if(ptr == NULL){
        return NULL;
    }
    else{
        removeAll(ptr->left);
        removeAll(ptr->right);
        free(ptr);
        ptr = NULL;
    }

    return ptr;
}

void preOrder(struct node *root){
 // insert code here
    if(root != NULL){
         printf("%15s || %15s || %15s ||\n", root->binusianID, root->binusianName, root->type);
        preOrder(root->left);
        preOrder(root->right);
    }
}

void print(struct node *root){
    if(root && isShow==true){
        printf("=========================================================\n");
        printf("||%15s || %15s || %15s ||\n", "Binusian ID", "Binusian Name", "Position");
        printf("=========================================================\n");
        preOrder(root);
        printf("=========================================================\n\n");
    }else{
        printf("No data ...\n");
    }
}

void validatePrintFlag(int checker){
    if(checker % 2 == 1) isShow = true;
    else isShow = false;
}

int getMenu(){
    int choice;
    printf("--------------------------------------------------\n");
    printf("|School of Computer Science Stakeholders Database|\n");
    printf("--------------------------------------------------\n");
    printf("1. Insert\n");
    if(!isShow)
        printf("2. Show View (Pre-Order)\n");
    else
        printf("2. Close View (Pre-Order)\n");
    printf("3. Exit\n");
    printf("Choice : ");
    scanf("%d", &choice);
    fflush(stdin);
    return choice;
}

void insertMenu(){
 // insert code here
    int tbinusianID;
    char tbinusianName[100];
    char tbinusianType[100];

 printf("Please input binusianID, binusianName, and binusianType\n");

    do{
        printf("Binusian ID [1...999]: ");
        scanf("%d", &tbinusianID); getchar();
    } while(tbinusianID < 1 || tbinusianID > 999);

    int len = 0;

    do{
        printf("Binusian Name [5..25]: ");
        scanf("%[^\n]", tbinusianName); getchar();
        len = strlen(tbinusianName);
    } while(len < 5 || len > 25);


    do{
        printf("Binusian type [Student / Lecturer]: ");
        scanf("%s", tbinusianType); getchar();
    } while (strcmpi(tbinusianType, stakeholder[0]) != 0 && strcmpi(tbinusianType, stakeholder[1]) != 0);
    
    root = insert(root, tbinusianID, tbinusianName, tbinusianType);

    printf("Successfully added...");
    getchar();
}

int main(){
    int choice;
    int checkerShow = 0;
    do{
        system("cls");
        if(isShow)
            print(root);
        choice = getMenu();
        switch(choice){
            case 1:
                insertMenu();
                break;
            case 2:
                checkerShow++;
                validatePrintFlag(checkerShow);
                print(root);
                break;
            case 3:
                removeAll(root);
                printf("Thank you");
                getchar();
                break;
        }
    }while(choice!=3);

    return 0;
}
