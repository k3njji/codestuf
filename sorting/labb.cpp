#include <stdio.h>
//Problem B
long long int sum(long long int total, long long int D, long long int N){
    while(N > 0){
        total += N;
        N--;
    }
    if(D == 1) return total;
    return sum(0, D-1, total);  
}

int main(){
    long long int D, N;
    scanf("%lld %lld", &D, &N);
    printf("%lld\n", sum(0, D, N));
}
