#include<stdio.h>
#include<string.h>
#include<stdlib.h>

//m = table size
int m = 23;

struct tnode{
 char value[10];
 int step;
}*ND[25];

int hashing(char value[10]){ 
 //complete the code to do hashing using division hashing function
 //add all the character ASCII in the string

 int len = strlen(value);
 int key = 0;

 for(int i = 0; i < len; i++){
  key += value[i];
 }
  
 return key % m;
}

struct tnode *newData(char value[10]){ 
 //complete the code to create a new tnode name ND
 struct tNode *ND = (tNode*)malloc(sizeof(tNode));

 strcpy(ND->value, value);
 
 return ND;
}

void insert(char value[10]){ 
 struct tnode *N_Data = newData(value);
 int key = hashing(value);
 
 //complete the code to insert new data to hash table. If there is any collision, use linear probing to solve it and show ‘TABLE IS FULL!!!’ when the hash table is full or the data cannot be insert to the table.
 if(ND[key] == NULL){
  ND[key] = N_Data;
  return;
 }
 else{
  int index = key;
  int counter = 0;

  while(ND[key] != NULL && index != key){
   key = (key + 1) % m;
   counter++;
  }

  if(index == key){
   puts("Table is Full!");
  }

  ND[key] = N_Data;
  ND[key]->step = counter;

  return;
 }
 
}

void view(){
 for(int i=0;i<m;i++){
  if(ND[i]) printf("[%d]\t%s (%d step(s))\n", i, ND[i]->value, ND[i]->step+1);
  else printf("[%d]\tNULL\n", i);
 }
}

int main(){
 for(int i=0;i<m;i++){
  ND[i] = NULL;
 }
 
 insert("AAAAA");
 insert("BBBBB");
 insert("CCCCC");
 insert("AAABB");
 insert("BABAA");
 insert("BAABA");
 insert("BBAAA");
 insert("ABBAA");
 
 
 view();
 return 0;
}
