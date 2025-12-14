#include<stdio.h>
#include<string.h>

int main()
{
	int t, n, a, b;
	char number[1005];
	char temp[1005];
	scanf("%d", &t); 
	for(int i=1; i<=t; i++)
	{
		scanf("%d %s", &n, number);
		for(int j=1; j<=n; j++)
		{
			scanf("%d %d", &a, &b); 
			a--;
			b--;
			strcpy(temp, number);
			for(int k=a, m=b; k<=b, m>=a; k++, m--)
			{
				number[k]= temp[m];
			}
		}
		printf("Case #%d: %s\n", i, number);
	}
	return 0;
}
