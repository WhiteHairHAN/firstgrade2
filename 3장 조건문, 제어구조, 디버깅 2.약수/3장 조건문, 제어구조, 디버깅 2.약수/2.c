#include<stdio.h>
void point_divisor(int value);
void main()
{
	int number;
	printf("������ �Է��Ͻÿ� :");
	scanf("%d", &number);
	if (number >= 2)
	{
		printf("%d �� ���� ����� ���մϴ�.\n", number);
		point_divisor(number);
	}
	else
		printf("����� ���� �� �����ϴ�.\n");
		printf("\n");
}

void point_divisor(int value)
{
	int n, remains;
	printf("%d �� ��� : ", value);
	for (n = 2; n <= value; n++)
	{
		remains = value %n;
		if (remains == 0)
			printf("%d ", n);
	}
	printf("\n");
}