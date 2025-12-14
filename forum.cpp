#include<stdio.h>

int main()
{
	int i;

  int *p;

  int ptp;

  i = 10;

  p = &i;

  ptp = &p;

  p = i;

  ptp = i;

  printf("nilai i = %d\n",i);

  printf("nilai p = %d\n",p);

  printf("nilai ptp = %d\n",**ptp);

  printf("nilai p = %x\n",p);

  printf("nilai ptp = %x\n",ptp);

}
