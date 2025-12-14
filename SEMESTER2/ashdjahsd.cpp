#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Node {
    char name[20];
    int quantity;
    float price;
    float total_cost;
    Node *prev;
    Node *next;
};

void insert(Node **head, char name[], int quantity, float price) {
    Node *new_node = new Node;
    strcpy(new_node->name, name);
    new_node->quantity = quantity;
    new_node->price = price;
    new_node->total_cost = (float)quantity * price;
    new_node->next = NULL;

    if (*head == NULL) {
        new_node->prev = NULL;
        *head = new_node;
        return;
    }

    Node *curr = *head;
    while (curr->next != NULL) {
        curr = curr->next;
    }

    curr->next = new_node;
    new_node->prev = curr;
}

Node* find_node(Node *head, char name[]) {
    Node *current = head;
    while (current != NULL) {
        if (strcmp(current->name, name) == 0) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void update(Node *head, char name[], int new_quantity) {
    Node *node = find_node(head, name);
    if (node == NULL) {
        printf("%s not found in list\n", name);
        return;
    }

    node->quantity = new_quantity;
    node->total_cost = (float)new_quantity * node->price;
}

void printList(Node *head) {
    Node *current = head;
    printf("%-10s %-10s %-10s %-15s\n", "Name", "Quantity", "Price", "Total Cost");
    printf("-----------------------------------------------------\n");
    while (current != NULL) {
        printf("%-10s %-10d $%.2f      $%.2f\n", current->name, current->quantity, current->price, current->total_cost);
        current = current->next;
    }
    printf("\n");
}


double getTotalCost(Node *head) {
    Node *temp = head;
    double total = 0.0;
    while (temp != NULL) {
        total += (temp->quantity * temp->price);
        temp = temp->next;
    }
    return total;
}

void freeList(Node *head) {
    Node *temp = head;
    while (temp != NULL) {
        Node *next = temp->next;
        free(temp);
        temp = next;
    }
}

int main() {
    Node *head = NULL;
    insert(&head, "Apple", 0, 0.50);
    insert(&head, "Banana", 0, 0.25);
    insert(&head, "Orange", 0, 0.60);
    insert(&head, "Pear", 0, 0.40);
    printList(head);

    while (true) {
        char input[50];
        printf("( Capital letter for the desired item e.g. Apple 3 ) \n");
        printf("Enter to input another fruit and quantity or press 'q' and enter to quit \n");
        printf("Enter fruit name and quantity: ");
        fgets(input, 50, stdin);
        if (input[0] == 'q') {
            break;
        }
        char *name = strtok(input, " ");
        int quantity = atoi(strtok(NULL, " "));
        update(head, name, quantity);
    }

    printf("\nYour shopping list:\n");
    printList(head);
    printf("-----------------------------------------------------\n");
    printf("Total cost: $%.2lf\n", getTotalCost(head));
    printf("-----------------------------------------------------\n");

    freeList(head);
    return 0;
}

