#include<stdio.h>

int main(){
    int array[20];
    int i;
    printf("Enter value to be stored in array>");
    for (i=0;i<20;i++){
        //printf("Enter value to be stored in array[%d]> ",i);
        scanf("%d,",&(array[i]));
        //scanf("%d,",(array+i));
    }
    for (i=0;i<20;i++){
        if (i==19){
            printf("%d\n",array[i]);
            //printf("%d\n",*(array+i));
        }
        else{
            printf("%d, ",array[i]);
        }
    }
    return 0;
}
