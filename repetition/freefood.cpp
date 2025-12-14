#include<stdio.h>

int main()
{

	int x, y, z;
	scanf("%d", &x);
	
	for(int i=1; i<=x; i++){
		scanf("%d %d", &y, &z);
		getchar();
		int k=0;
		int arr[y];
		for(int h=0; h<y; h++){
			scanf("%d", &arr[h]);
			k+=arr[h];
		}
		if(k>z){
			printf("Case #%d: Wash dishes\n", i);
		}else{
			printf("Case #%d: No worries\n", i);
		}
		
	}

	return 0;
}
