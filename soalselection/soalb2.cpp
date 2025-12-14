#include<stdio.h>

int main()
{
	int d, k, n, m;
	scanf("%d", &d);
	int arr[1000];
	int i;
	
	for(i=1; i<=d; i++){
		scanf("%d %d %d", &k, &n, &m);
		if(k>n+m){
			printf("Case #%d: no\n", i);
		} else {
			printf("Case #%d: yes\n", i);
		}
		arr[i];
		getchar();
	}
	
	
	return 0;
}
