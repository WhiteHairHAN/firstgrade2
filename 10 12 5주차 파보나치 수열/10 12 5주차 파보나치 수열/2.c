#include<stdio.h>
int fibo(int num);

int main(void)
{
	int num;
	int i;
	printf("\n 파보나치 수 입력 :");
	scanf("%d", &num);
	for (i = 0; i < num; i++)
	{
		printf("%d", fibo(i));
	}
	printf("\n\n");
	return 0;
}

int fibo(int num)
{
	if (num == 0)
		return 0;
	else if (num == 1)
		return 1;
	else
		return fibo(num - 1) + fibo(num - 2);
}