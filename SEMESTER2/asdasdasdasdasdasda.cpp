#include<stdio.h>
#include<string.h>
#include<stdlib.h>
//m = table size int m = 23;
const int max = 23;
struct tnode{
char value[10]; int step;
}*ND[25];


int hashing(char value[10]){
//complete the code to do hashing using division hashing
//add all the character ASCII in the string


return key;
}


struct tnode *newData(char value[10]){
//complete the code to create a new tnode name ND


return ND;
}


void insert(char value[10]){
struct tnode *N_Data = newData(value); int key = hashing(value);

//complete the code to insert new data to hash table. If there is any collision, use linear probing to solve it and show 'TABLE IS FULL!!!' when the hash table is full or the data cannot be insert to the table.
}


int main(){
for(int i=0;i<m;i++){ ND[i] = NULL;
}

insert("AAAAA");
insert("BBBBB");
insert("CCCCC");
insert("AAABB");
insert("BABAA");
insert("BAABA");
insert("BBAAA");
insert("ABBAA");

view(); return 0;
}

