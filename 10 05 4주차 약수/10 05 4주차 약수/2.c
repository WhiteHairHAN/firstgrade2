#include<stdio.h>

void main()
{
	int number;
	while (1)
	{
		printf("����� ���� ������ �Է��ϼ���(1������ ���� ����):");
		scanf("%d", &number);
		if (number >= 2)
		{
			printf("%d �� ���� ����� ���մϴ�. \n", number);
			print_divisor(number);
		}
		else
		{
			printf("%d�� ���� ����� ���� �� �����ϴ�.\n", number);
			printf("���α׷��� �����մϴ�\n");
			break;
		}
		printf("\n");
	}
}

int print_divisor(int value)
{
	int n, remains;
	printf("%d �� ��� :", value);
	for (n = 2; n <= value; n++)
	{
		remains = value %n;
		if (remains == 0)
			printf("%d ", n);
	}
	printf("\n");
}