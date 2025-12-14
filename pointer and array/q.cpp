#include<stdio.h>

int main()
{
	int t, n, temp, count, threeOn, noThreeOn;
	int arr[105];
	scanf("%d", &t);
	for(int i=0; i<t; i++)
	{
		count=0;
		scanf("%d", &n);
		for(int j=0; j<n; j++)
		{
			scanf("%d", &arr[j]);
		}
		threeOn=0;
		noThreeOn=0;
		for(int j=0; j<n-1; j++)
		{
			for(int k=j+1; k<n; k++)
			{
				temp=arr[j]^arr[k];
				count=0;
				while(temp>0)
				{
					count+=temp&1;
					temp>>=1;
				}
				//printf("%d ^ %d = %d\n", arr[j], arr[k], count);
				if(count>=3)
					threeOn++;
				else
					noThreeOn++;
			}
		}
		printf("Case #%d: %d %d\n", i+1, threeOn, noThreeOn);
	}
	return 0;
}
