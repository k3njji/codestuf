#include <stdio.h>
#include <stdlib.h>

// Define a structure for a node in the linked list
struct Node {
    int data;
    int priority;
    struct Node* next;
};

// Define a structure for the linked list
struct LinkedList {
    struct Node* head;
};

// Initialize an empty linked list
void initLinkedList(struct LinkedList* list) {
    list->head = NULL;
}

// Create a new node with given data and priority
struct Node* makeNode(int data, int priority) {
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->priority = priority;
    node->next = NULL;
    return node;
}

// Insert a node into the linked list in descending order of priority
void insert(struct LinkedList* list, int data, int priority) {
    struct Node* newNode = makeNode(data, priority);
    if (list->head == NULL) {
        list->head = newNode;
        return;
    }
    if (priority > list->head->priority) {
        newNode->next = list->head;
        list->head = newNode;
        return;
    }
    struct Node* temp = list->head;
    while (temp->next != NULL && temp->next->priority >= priority) {
        temp = temp->next;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

// Remove and return the node with highest priority
struct Node* removeHighestPriority(struct LinkedList* list) {
    struct Node* highestPriority = list->head;
    if (highestPriority == NULL) {
        return NULL;
    }
    list->head = list->head->next;
    return highestPriority;
}

// Display the contents of the linked list
void display(struct LinkedList* list) {
    struct Node* temp = list->head;
    while (temp != NULL) {
        printf("%d [%d] -> ", temp->data, temp->priority);
        temp = temp->next;
    }
    printf("NULL\n");
}

int main() {
    struct LinkedList list;
    initLinkedList(&list);

    insert(&list, 5, 1);
    display(&list);

    insert(&list, 10, 2);
    display(&list);

    insert(&list, 15, 3);
    display(&list);

    removeHighestPriority(&list);
    display(&list);

    insert(&list, 20, 4);
    display(&list);


}
