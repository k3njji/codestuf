#include <stdio.h>
#include <stdlib.h>

struct Node
{
  int value;
  Node *next, *prev; // store the address of another Node
} *head, *tail;      // global var to store the address of first and last node in the LL

Node *createNode(int value)
{
  // allocate memory with size of Node and cast it to Node*
  Node *newNode = (Node *)malloc(sizeof(Node));
  newNode->value = value; // fill in the value with the given parameeter
  newNode->next = NULL;   // at first, next node is set to NULL
  newNode->prev = NULL;   // at first, the previous node is set to NULL
  return newNode;         // return the newly created Node
}

void readNode(Node *currentNode)
{
  printf("Value: %d\n", currentNode->value);
  printf("Alamat node sebelumnya: %p\n", currentNode->prev);
  printf("Alamat node sekarang: %p\n", currentNode);
  printf("Alamat node setelahnya: %p\n", currentNode->next);
}

// Coba implementasikan push tail menggunakan konsep DLL
void pushTail(int value)
{
  Node *temp = createNode(value); // create the new node
  if (!head)                      // if there's no head a.k.a. we have an empty LL
  {
    head = tail = temp; // tail will be the new head and the new tail
  }
  else
  {
    // Current: NULL <- 50 (head) <-> 30 <-> 40 <-> 20 (tail) -> NULL
    // Goal: NULL <- 50 (head) <-> 30 <-> 40 <-> 20 (tail) <-> temp -> NULL
    tail->next = temp; // current tail will point to the newly created node
    temp->prev = tail; // the new node will point to the current tail
    tail = temp;       // the new node will be the last node in the LL (new tail)
  }
}

void pushHead(int value)
{
  Node *temp = createNode(value); // create the new node
  if (!head)                      // if there's no head a.k.a, we have an empty LL (head == NULL)
  {
    head = tail = temp;
  }
  else
  {
    // NULL <- B (temp) -> A (head) -> NULL
    temp->next = head; // make the current new node to point to the current old head
    // NULL <- B (temp) -><- A (head) -> NULL
    head->prev = temp; // the current head will point to the newly created node
    // NULL <- B (temp, head) -><- A -> NULL
    head = temp; // replace head to the current new node
  }
}

// pushMid will always make the LL sorted
// pushMid(10)
// pushMid(5)
// pushMid(15)
// Result: 5 -> 10 -> 15
void pushMid(int query)
{
  if (!head || query < head->value) // if LL empty / query is smaller than head
  {
    pushHead(query);
  }
  else if (query > tail->value) // if query is greater than tail
  {
    pushTail(query);
  }
  else
  {
    Node *newNode = createNode(query); // 12 (newNode)
    Node *current = head;              // 5 (head, current) -> 10 -> 15 -> ...
    while (current->value < query)
    {
      current = current->next;
    }

    // Condition: 5 (head) -> 10 (current) -> 15 -> ...
    // Objective: 5 (head) -> 10 (current) -> 12 (newNode) -> 15 -> ...
    newNode->prev = current;
    newNode->next = current->next;
    current->next->prev = newNode;
    current->next = newNode;
  }
}
// Case: NULL <- A -><- B -><- C -> NULL
// Objective: NULL <- A -><- C -> NULL
// Asumsi linked list is sorted, query is the number to be deleted

void popHead()
{
  if (!head) // if there's no head a.k.a, we have an empty LL (head == NULL)
  {
    return; // do nothing
  }
  else if (head == tail) // if there's only one node
  {
    free(head);         // free allocated memory
    head = tail = NULL; // set the address into NULL
  }
  else // if there's mode than one node
  {
    Node *newHead = head->next;        // NULL <- A (head) -><- B (newHead) -><- C -> NULL
    head->next = newHead->prev = NULL; // NULL <- A (head) -> NULL || NULL <- B (newHead) -><- C -> NULL
    free(head);                        // NULL <- B (newHead) -><- C -> NULL
    head = newHead;                    // NULL <- B (head, newHead) -><- C -> NULL
  }
}

void popTail()
{
  if (!head) // if there's no node in LL
  {
    return; // do nothing
  }
  else if (head == tail) // if there's only 1 node
  {
    free(head);         // free allocated memory
    head = tail = NULL; // set the address into NULL
  }
  else // if there's more than 1 node, we need a new tail candidate
  {
    Node *newTail = tail->prev;        // NULL <- A -><- B (newtail) -><- C (tail) -> NULL
    newTail->next = tail->prev = NULL; // NULL <- A -><- B (newtail) -> NULL || NULL <- C (tail) -> NULL
    free(tail);                        // NULL <- A -><- B (newtail) -> NULL
    tail = newTail;                    // NULL <- A -><- B (tail, newtail) -> NULL
  }
}

void popMid(int query)
{
  if (!head)
  {
    return;
  }
  else if (head->value == query) // if the query is the first element
  {
    popHead();
  }
  else if (tail->value == query) // if the query is the last element
  {
    popTail();
  }
  else // if the query is in the middle of the LL
  {
    // Case: NULL <- A -><- B -><- C -><- D -><- E -> NULL
    // Objective: NULL <- A -><- B -><- D -><- E -> NULL

    // 1. Find the node that needs to be deleted
    Node *current = head;
    while (current && current->value != query) //
    {
      current = current->next; // traverse until we have find the value to be deleted
    }

    // 2. NULL <- A -><- B -><- C (current) -><- D -><- E -> NULL
    current->prev->next = current->next;  // B->next = D
    current->next->prev = current->prev;  // D->prev = B
    current->prev = current->next = NULL; // isolate current node
    free(current);                        // free assigned memory
    current = NULL;                       // remove value
  }
}

void printLinkedList()
{
  for (Node *temp = head; temp != NULL; temp = temp->next)
  {
    readNode(temp);
    puts("|");
    puts("|");
    puts("v");
  }
  puts("NULL");
  // for (int i = 0; i < 10; i = i + 1)
  // {
  //   printf("%d", i);
  // }
}

int main()
{
  pushTail(10);
  pushTail(15);
  pushHead(30);
  printLinkedList();
  popTail();
  popHead();
  popTail();
  printLinkedList();
  popHead();
  printLinkedList();

  return 0;
}
