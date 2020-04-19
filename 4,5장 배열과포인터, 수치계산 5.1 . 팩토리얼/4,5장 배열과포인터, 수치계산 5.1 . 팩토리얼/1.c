/* 순환호출하지 않은 함수

#include<stdio.h>
void main()
{
	int n;
	int ifact = 1;
	double dfact = 1.0;

	printf(" n        정수 팩토리얼          실수팩토리얼\n");
	printf("===================================================================\n");

	for (n = 1; n <= 20; n++)
	{
		ifact = ifact *n;
		dfact = dfact *(double)n;
		printf("%2d : %20d %20.0lf\n", n, ifact, dfact);
	}
}  */

/* 순환호출 함수를 쓰는 방법
#include<stdio.h>
int factorial(int n);

void main()
{
	int n, ifact = 1;
	printf(" n        정수팩토리얼\n");
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