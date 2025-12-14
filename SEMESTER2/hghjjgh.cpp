#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node 
{
    char data;
    struct Node* next;
    struct Node* prev;
} Node;

void insert(Node** head_ref, char data)
 {
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->data = data;
    new_node->prev = NULL;
    new_node->next = (*head_ref);

    if (*head_ref != NULL) {
        (*head_ref)->prev = new_node;
    }

    *head_ref = new_node;
}

void sort_reverse(Node** head_ref) 
{
    Node* current = *head_ref;
    Node* temp = NULL;

    while (current != NULL) 
{
        temp = current->prev;
        current->prev = current->next;
        current->next = temp;
        current = current->prev;
    }

    if (temp != NULL) {
        *head_ref = temp->prev;
    }
}

void print_list(Node* node) 
{
    printf("sorted: ");
    while (node != NULL) {
        printf("%c", node->data);
        node = node->next;
    }

    printf(" -> (reverse) -> ");

    while (node != NULL && node->next != NULL) 
{
        node = node->next;
    }

    while (node != NULL) 
{
        printf("%c", node->data);
        node = node->prev;
    }
}


int main() {
    Node* head = NULL;
    char input[100];
    fgets(input, 100, stdin);
    for (int i = 0; i < strlen(input); i++) 
    {
        if (input[i] == '\n') 
{
            continue;
        }
        insert(&head, input[i]);
    }
    sort_reverse(&head);
    print_list(head);

    return 0;
}

