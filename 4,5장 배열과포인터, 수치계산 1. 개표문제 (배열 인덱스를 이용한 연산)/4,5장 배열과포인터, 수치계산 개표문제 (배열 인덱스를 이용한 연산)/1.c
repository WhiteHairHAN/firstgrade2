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
	printf("1~4번 중 한 후보의 번호를 입력하시오 :");
	while (scanf("%d", &xdata) == 1)
	{
		n++;
		if (xdata<1 || xdata>NMAX)
			++ip[0];
		else
			++ip[xdata];
		printf("1~4번 중 한 후보의 번호를 입력하시오");
	}

	printf("\n득표수 \n");
	for (i = 1; i < NMAX; i++)
		printf("%d 번  : %d 표\n", i, ip[i]);
	printf("\n 무효표 %d 표", ip[0]);
	printf("\n총투푯수  %d\n ", n);
}