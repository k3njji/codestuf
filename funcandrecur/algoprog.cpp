#include<stdio.h>

int count = 0;
//count is global variable


int addition(int x, int y){
	int sum = x+y;
	count++;
	printf("%d\n", count);
	return sum;
}

//void ga return any value (biasanya dipake buat ngeoutput tulisan//sama kayak modul)
void printResult(int hasil){
	printf("The result is %d\n", hasil);
}

//make pass by reference
void swapNumber(int *x, int *y){
	int temp=*x;
	*x=*y;
	*y=temp;
	printf("x is %d, y is %d\n", *x, *y);
}
//for 1d array in function you can leave it be be, but nor for >1d array
void printName(char name[]){
	name[0]='D';
	printf("%s\n", name);
}

int main()
{
	int x, y, res;
	char name[20]="Kenzie";
	
	//function to sum x and y (x and y is local variable
	scanf("%d %d", &x, &y);
	res=addition(x, y);
	printResult(res);
	swapNumber(&x, &y);
	printName(name);
	
	printf("%d", res);
	return 0;
}
