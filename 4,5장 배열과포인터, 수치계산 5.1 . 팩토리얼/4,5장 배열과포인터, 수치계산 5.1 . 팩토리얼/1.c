/* ��ȯȣ������ ���� �Լ�

#include<stdio.h>
void main()
{
	int n;
	int ifact = 1;
	double dfact = 1.0;

	printf(" n        ���� ���丮��          �Ǽ����丮��\n");
	printf("===================================================================\n");

	for (n = 1; n <= 20; n++)
	{
		ifact = ifact *n;
		dfact = dfact *(double)n;
		printf("%2d : %20d %20.0lf\n", n, ifact, dfact);
	}
}  */

/* ��ȯȣ�� �Լ��� ���� ���
#include<stdio.h>
int factorial(int n);

void main()
{
	int n, ifact = 1;
	printf(" n        �������丮��\n");
	printf("=============================\n");
	for (n = 1; n <= 12; n++)
	{
		ifact = factorial(n);
		printf("%2d : %20d\n", n, ifact);

	}
}

int factorial(int n)
{
	if (n == 1)
		return 1;
	else
		return n*factorial(n - 1);
}

*/