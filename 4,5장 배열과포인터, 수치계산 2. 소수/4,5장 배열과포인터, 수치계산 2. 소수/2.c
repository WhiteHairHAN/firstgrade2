#include<stdio.h>
#include<math.h>

int is_prime(int n);

int main()
{
	int number;
	int a;
	while (1)
	{
		printf("�Ҽ��� ������ ������ �Է��ϼ��� ( 1������ ���̸� ����)");
		scanf("%d", &number);
		if (number >= 2)
		{
			printf("%d �� ���� �Ҽ��� �����մϴ�.", number);
			a = is_prime(number);
			if (a == 1)
				printf("�Ҽ��Դϴ�.\n");
			else
				printf("�Ҽ��� �ƴմϴ�.\n");
		}
		else
			printf("���α׷��� �����մϴ�.");
	}
	return 0;
}
// ��� 1 ���� �߻�;
/*
int is_prime(int n)
{
	int divider, to;

	to = (int)sqrt((double)n);
	divider = 2;
	while (divider <= to)
	{
		if ((n%divider) == 0);
		{
			return 0;
		}
		divider += 1;
	}
	return 1;
}*/

int is_prime(int n)
{
	int divider, to;
	int prime = 1;

	to = (int)sqrt((double)n);
	divider = 2;
	while (divider  <= to)
	{
		if ((n%divider) == 0)
		{
			prime = 0;
			break;
		}
		divider += 1;
	}
	return prime;
}
