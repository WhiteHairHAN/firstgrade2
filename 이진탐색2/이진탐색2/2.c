#include<stdio.h>

int bs(int list[], int sn, int left, int right);

void main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int i, sn = 0,index = 0;

	printf("  i  :");
	for (i = 0; i < 10; i++)
	{
		printf("%d ", i);
	}
	
	printf("sn : ");
	scanf("%d", &sn);

	index = bs(a, sn, 0, 9);
	printf("%d is in a [%d]", sn, index);
}

int bs(int list[], int sn, int left, int right)
{
	int mid = 0;
	mid = (left + right) / 2;

	

	if (list[mid] == sn)
		return mid;
	else if (list[mid] > sn)
		return bs(list, sn, left, mid - 1);
	else
		return bs(list, sn, mid - 1, right);
}