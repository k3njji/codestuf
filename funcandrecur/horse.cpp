#include<stdio.h>

void check(int kotak1, int kotak2, int numb1, int numb2, int x, int result){
	
	if(kotak1<1 || kotak2>8 || numb1<1 || numb2>8){
		return;
	}
	
	if(kotak1==kotak2 && numb1==numb2){
		result=1;
		return;
	}
	
	if(x>0){
		check(kotak1-1, kotak2, numb1-2, numb2, x-1, result);
		check(kotak1+1, kotak2, numb1+2, numb2, x-1, result);
		check(kotak1-2, kotak2, numb1-1, numb2, x-1, result);
		check(kotak1+2, kotak2, numb1+1, numb2, x-1, result);
		check(kotak1-1, kotak2, numb1+2, numb2, x-1, result);
		check(kotak1+1, kotak2, numb1-2, numb2, x-1, result);
		check(kotak1-2, kotak2, numb1+1, numb2, x-1, result);
		check(kotak1+2, kotak2, numb1-1, numb2, x-1, result);
	}
}

int main()
{
	int x;
	scanf("%d", &x);
	x*=2;
	int numb1, numb2;
	char alp1, alp2;
	scanf("%c%d %c%d", &alp1, &numb1, &alp2, &numb2);
	
	int kotak1=alp1-'A'+1;
	int kotak2=alp2-'A'+1;
	
	printf("%d %d", kotak1, kotak2);
	int result = 0;
	check(kotak1, kotak2, numb1, numb2, x*2, result);
	printf("%d", result);
	
	
	return 0;
}
