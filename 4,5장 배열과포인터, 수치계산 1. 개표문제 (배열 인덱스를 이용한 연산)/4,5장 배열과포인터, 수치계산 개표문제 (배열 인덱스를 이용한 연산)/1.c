#include<stdio.h>
#define NMAX 5
void main()
{
	int ip[NMAX], n, xdata = 0,i;
	n = 0;
	for (i = 0; i < NMAX; ++i)
	{
		ip[i] = 0;
	}
	printf("1~4�� �� �� �ĺ��� ��ȣ�� �Է��Ͻÿ� :");
	while (scanf("%d", &xdata) == 1)
	{
		n++;
		if (xdata<1 || xdata>NMAX)
			++ip[0];
		else
			++ip[xdata];
		printf("1~4�� �� �� �ĺ��� ��ȣ�� �Է��Ͻÿ�");
	}

	printf("\n��ǥ�� \n");
	for (i = 1; i < NMAX; i++)
		printf("%d ��  : %d ǥ\n", i, ip[i]);
	printf("\n ��ȿǥ %d ǥ", ip[0]);
	printf("\n����ǩ��  %d\n ", n);
}