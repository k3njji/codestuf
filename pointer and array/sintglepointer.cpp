#include<stdio.h>
#include<string.h>
int main()
{
	//1
	int a;
	a = 20;
	
	int *ptr_a;
	ptr_a = &a;
	
	printf("value of a: %d\n", a);
	printf("addres of a: %d\n", &a);
	
	printf("value of ptr_a: %d\n", ptr_a);
	printf("value a through ptr_a: %d\n", *ptr_a);
	printf("address of ptr_a: %d\n", &ptr_a);
	
	*ptr_a = 10;
	printf("value of a: %d\n", a);
	//& -> get variable address
	//* -> get value of the variab;es through pointer
	
	//double pointer
	int **ptr_ptr_a;
	ptr_ptr_a = &ptr_a;
	printf("value of ptr_ptr_a: %d\n", ptr_ptr_a);
	printf("value of a through ptr_ptr_a: %d\n", **ptr_ptr_a);
	
	//one dimensional array
	int num_array[] = {4, 3, 2, 1, 10, 7, 8, 3, 100, 2};
	//the array always starts from 0
//	printf("%d\n", num_array[0]);

//	for(int i = 0; i<sizeof(num_array)/sizeof(int); i++){
//		printf("index %d: %d\n", i, num_array[i]);
//	}
	
//	char str[100]="abcde";
//	printf("strlen: %d\n", strlen(str));
//	printf("strlen: %d\n", sizeof(str));
	
	
//	int n;
//	scanf("%d", &n);
//	getchar();
//	int num[n] = {};
//	for(int i=0; i<n; i++){
//		scanf("%d", &num[i]);
//	}for(int i=0; i<n; i++){
//		printf("%d\n", num[i]);
//	}
	
	
//multidimensional array
int num_table[5][2] = {
						{1, 3},
						{2, 6},
						{-1, 7},
						{11, 4},
						{100, },
						};
						
	for(int k=0; k<5; k++){
		for(int j=0; j<2; j++){
			printf("%d", num_table[k][j]);
		}
	}
	
	
	
	
	
	
	
	
	
	
	
	return 0;
}
