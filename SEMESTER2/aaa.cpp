#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>


struct Node
{
   char string;
   Node *next;
   Node *prev;
} *head, *tail;


Node *createNode(char string)
{
   Node *newNode = (Node *)malloc(sizeof(Node));
   newNode->string = string;
   newNode->next = newNode->prev = NULL;
   return newNode;
}


// values goes in and out through only one enterance.


void pushTail(char string)
{
   Node *newNode = createNode(string);
   if (head == NULL)
   {
       head = tail = newNode;
   }
   else
   {
       tail->next = newNode;
       newNode->prev = tail;
       tail = newNode;
   }
}


void popTail()
{
   if (head == NULL)
   {
       return;
   }
   else if (head == tail)
   {
       head = NULL;
       tail = NULL;
       free(head);
   }
   else
   {
       Node *curr = tail;
       tail = curr->prev;
       tail->next = NULL;
       free(curr);
   }
}


int priority(char op) // priority is to acknowledge the hierarchy of operators.
{
   if (op == '(')
   {
       return 0;
   }
   else if (op == '+' || op == '-')
   {
       return 1;
   }
   else if (op == '*' || op == '/')
   {
       return 2;
   }
   else
   {
       return 0;
   }
}


int main()
{
   char string[1000];
   int i, len;
   char op;
   int validity = 1;


   printf("Enter the expression: ");
   fgets(string, sizeof(string), stdin); // stdin -> standard input, where data is sent and read by the program.
   len = strlen(string);


   for (i = len - 1; i >= 0; i--)
   {
       if (string[i] == ' ' || string[i] == '\n')
       {
           continue;
       }
       else if (isalnum(string[i]))
       {
           printf("%c", string[i]);
       }
       else if (string[i] == ')')
       {
           pushTail(string[i]);
       }
       else if (string[i] == '(')
       {
           while (tail != NULL && tail->string != ')')
           {
               printf("%c", tail->string);
               popTail();
           }
           if (tail == NULL)
           {
               printf("Error: There were no closing parentheses to match this opening parenthesis.\n");
               return -1;
           }
           else
           {
               popTail();
           }
       }
       else
       {
           while (tail != NULL && priority(tail->string) > priority(string[i]))
           {
               printf("%c", tail->string);
               popTail();
           }
           pushTail(string[i]);
       }
   }
   while (tail != NULL)
   {
       printf("%c", tail->string);
       popTail();
   }


   return 0;
}

