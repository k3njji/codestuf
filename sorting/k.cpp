#include<stdio.h>

int main()
{
    long int i,j,k,l,test,numbers[25],temp,result[5];
    scanf("%ld",&test);
    for(l=1;l<=test;l++){
        for(i=0;i<25;i++){
            scanf("%ld",&numbers[i]);
        }
        for(i=0;i<24;i++){
            for(j=0;j<24-i;j++){
                if(numbers[j]>numbers[j+1]){
                    temp=numbers[j];
                    numbers[j]=numbers[j+1];
                    numbers[j+1]=temp;
                }
            }    
        }
        result[0]=numbers[0]/2;
        result[1]=numbers[1]-result[0];
        result[4]=numbers[24]/2;
        result[3]=numbers[23]-result[4];
        if(numbers[21]==(result[3]*2)){
            result[2]=numbers[20]-result[4];
        }
        else{
            result[2]=numbers[21]-result[4];
        }
        
        
        printf("Case #%ld:",l);
        for(i=0;i<5;i++){
            printf(" %ld",result[i]);
        }
        printf("\n");
    }
    return 0;
}
