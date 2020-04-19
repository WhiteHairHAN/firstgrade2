#include<stdio.h>
#include<math.h>

void triangle(int a, int b, int c);
int find_max(int a, int b, int c);

void main()
{
	int a, b, c, num1, num2, max;
	printf("3���� ������ �Է����ּ���\n\n");
	scanf("%d", &a);
	scanf("%d", &b);
	scanf("%d", &c);

	max = find_max(a, b, c);
	if (max == a)
	{
		num1 = b;
		num2 = c;
	}
	else if (max == b)
	{
		num1 = a;
		num2 = c;
	}
	else
	{
		num1 = a;
		num2 = b;
	}
	triangle(max, num1, num2);
}

int find_max(int a, int b, int c)
{
	int max;
	if (a > b)
		if (a > c)
			max = a;
		else
			max = c;
	else
		max = (b > c) ? b : c;
	return max;
}

void triangle(int max, int num1, int num2)
{
	if (num1 + num2 > max)
		if ((int)pow((double)num1, 2.0) + (int)pow((double)num2, 2.0) == (int)pow((double)max, 2.0))
			printf("�����ﰢ���̴�\n");
		else
			printf("�����ﰢ���� �ƴϴ�.\n");

	else
		printf("�ﰢ���� �̷� ������.\n");
}