#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 20

struct Node{
    char name[50];
    int age;
} *table[SIZE];

struct Node *nodeMaker(char name[], int age){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));

    strcpy(temp->name, name);
    temp->age = age;

    return temp;
}  

int hashFunction(char name[]){

    int key = 0;
    for(int i = 0; i < strlen(name); i++){
        key += name[i];
    }

    return key % SIZE;
}

void insert(char name[], int age){
    struct Node *temp = nodeMaker(name, age);
    int key = hashFunction(name);

    if(table[key] == NULL){
        table[key] = temp;
    }
    else{
        while(table[key] != NULL){
            key = (key + 1);
        }

        table[key] = temp;
        return;
    }
}

void pop(char name[]){
   


     for(int i = 0; i < SIZE; i++){
         if(table[i] != NULL && strcmp(table[i]->name, name) == 0){
             free(table[i]);
             table[i] = NULL;
             return;
         }
     }

         printf("No data found\n");

    return;
}

void searching(char name[]){
    int flag = 0;
    for(int i = 0; i < SIZE; i++){
        if(table[i] != NULL){
            if(strcmp(table[i]->name, name) == 0){
                printf("Value found! %s - %d di index %d!\n", table[i]->name, table[i]->age, i);
                flag = 1;
                break;
            }
        }
    }

    if(flag == 0){
        printf("Data not found!\n");
    }
}

void printAll(){
    for(int i = 0; i < SIZE; i++){
        printf("%d: ", i);

        if(table[i] != NULL){
            printf("Name: %s - Age: %d\n", table[i]->name, table[i]->age);
        }
        else{
            printf("NULL\n");
        }
    }

}

int main(){
    insert("aldrich", 20);
    insert("anton", 10);
    insert("richald", 20);
    insert("dlricha", 20);

    pop("lala");

    searching("richald");

    printAll();

    return 0;
}
