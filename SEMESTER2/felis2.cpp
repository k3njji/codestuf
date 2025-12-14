#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node{
   char code[5];
   char product[50];
   int quantity;
   long long int price;
   struct Node *next;
   struct Node *prev;
} *headMenu = NULL, *tailMenu = NULL, *headOrder = NULL, *tailOrder = NULL;


struct Node *createNewNode(char code[], char product[], long long int price){
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));


   strcpy(temp->code, code);
   strcpy(temp->product, product);
   temp->price = price;
   temp->quantity = NULL;
   temp->next = NULL;
   temp->prev = NULL;


   return temp;
}


struct Node *createNewNodeOrder(char code[], char product[], long long int price, int quantity){
   struct Node *temp = (struct Node*)malloc(sizeof(struct Node));


   strcpy(temp->code, code);
   strcpy(temp->product, product);
   temp->quantity = quantity;
   temp->price = price * quantity;
   temp->next = NULL;
   temp->prev = NULL;


   return temp;
}


void printOrder(){
   struct Node *curr = headOrder;


   if(curr == NULL){
       return;
   }
   else{
       while(curr != NULL){
           printf("Code: %s\nProduct: %s\nQuantity: %d\nPrice: %lld\n", curr->code, curr->product, curr->quantity, curr->price);
           puts("");
           curr = curr->next;
       }
   }
}


void mainMenu(){
   printOrder();
   puts("Menu");
   puts("==========");
   puts("1. Buy");
   puts("2. Update");
   puts("3. Exit");
}


void pushMenu(char code[], char product[], long long int price){
   struct Node *curr = createNewNode(code, product, price);


   if(headMenu == NULL){
       headMenu = tailMenu = curr;
   }
   else{
       curr->next = headMenu;
       headMenu->prev = curr;
       headMenu = curr;
   }
}


void pushOrder(char code[], char product[], long long int price, int quantity){
   struct Node *curr = createNewNodeOrder(code, product, price, quantity);
   struct Node *temp = headOrder;


   while(temp != NULL){
       if(strcmp(temp->code, code) == 0){
           temp->quantity = temp->quantity + quantity;
           temp->price = quantity*curr->price;
      
           return;
       }
       temp = temp->next;
   }


   if(headOrder == NULL){
       headOrder = tailOrder = curr;
   }
   else{
       tailOrder->next = curr;
       curr->prev = tailOrder;
       tailOrder = curr;
   }
  
}


void searching(char productCode[], int qty){
   if(headMenu == NULL){
       printf("Product does not exist!\n");
       return;
   }
   else if(strcmp(headMenu->code, productCode) == 0){
       pushOrder(productCode, headMenu->product, headMenu->price, qty);
   }
   else if(strcmp(tailMenu->code, productCode) == 0){
       pushOrder(productCode,tailMenu->product, tailMenu->price, qty);
   }
   else{
       struct Node *curr = headMenu;
       int index = 0;
       int flag = 0;
       while(curr != NULL){
           if(strcmp(curr->code, productCode) == 0){
               pushOrder(productCode, curr->product, curr->price, qty);
               flag = 1;
               break;
           }
           curr = curr->next;
           index++;
       }


       if(flag == 0){
           printf("Product doesn't exist\n");
       }


       return;
   }  
}


void orderUpdate(struct Node *change, char code[], char product[], long long int price, int quantity){
   int temp = change->price/change->quantity;
   change->quantity = quantity;
   change->price = change->quantity*temp;
   // change->price = *quantity;
   return;
}


void searchingOrder(char productCode[], int qty){
   if(headOrder == NULL){
       printf("Product does not exist!\n");
       return;
   }
   else if(strcmp(headOrder->code, productCode) == 0){
       orderUpdate(headOrder, productCode, headOrder->product, headOrder->price, qty);
   }
   else if(strcmp(tailOrder->code, productCode) == 0){
       orderUpdate(tailOrder, productCode,tailOrder->product, tailOrder->price, qty);
   }
   else{
       struct Node *curr = headMenu;
       int index = 0;
       int flag = 0;
       while(curr != NULL){
           if(strcmp(curr->code, productCode) == 0){
               orderUpdate(curr, productCode, curr->product, curr->price, qty);
               flag = 1;
               break;
           }
           curr = curr->next;
           index++;
       }


       if(flag == 0){
           printf("Product doesn't exist\n");
       }


       return;
   }  
}


void update(){
   char pcUpdate[5];
   int qty;


   printf("Input the product code you would like to update: ");
   scanf("%s", pcUpdate); getchar();
   printf("Input the quantity you want: ");
   scanf("%d", &qty); getchar();


   searchingOrder(pcUpdate, qty);
}


void printMenu(){
   struct Node *curr = headMenu;


   if(curr == NULL){
       return;
   }
   else{
       while(curr != NULL){
           printf("Code: %s\nProduct: %s\nPrice: %lld\n", curr->code, curr->product, curr->price);
           puts("");
           curr = curr->next;
       }
   }
}


void mauOrder(){
   int qty;
   char productCode[5];


   printf("Input Product Code: ");
   scanf("%s", productCode); getchar();
   printf("Input Quantity: ");
   scanf("%d", &qty); getchar();
   searching(productCode, qty);
   puts("");
   printOrder();
}


int main(){
   //insert products
   pushMenu("A4", "Oreo", 7000);
   pushMenu("A3", "Bread", 10000);
   pushMenu("A2", "Fruit Tea", 5000);
   pushMenu("A1", "Mineral Water", 2000);
   pushMenu("A0", "Milk Tea", 3000);


   int choice, no;


   do{
       mainMenu();
       printf(">> ");
       scanf("%d", &choice); getchar();


       switch(choice){
           case 1:
               printMenu();
               mauOrder();


               do{
                   printf("Do you want to add another product?\n");
                   puts("1. Yes");
                   puts("2. No");
                   printf(">> ");
                   scanf("%d", &no); getchar();
                   puts("");


                   switch(no){
                       case 1:
                           mauOrder();
                           break;
                   }
               } while(no != 2);
              
               break;
           case 2:
               update();
               break;
       }
   } while(choice != 3);


   return 0;
}
