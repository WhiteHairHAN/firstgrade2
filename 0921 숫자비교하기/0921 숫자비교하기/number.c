#include<stdio.h>

float find_max(float a, float b, float c);
float find_min(float a, float b, float c);

void main()
{
	float num1, num2, num3, max, min, diff;
	printf("������ �Է��ϼ���\n");
	printf("ù��°�� :");
	scanf("%f", &num1);
	printf("�ι�°�� :");
	scanf("%f", &num2);
	printf("����°�� :");
	scanf("%f", &num3);

	max = find_max(num1,num2,num3);
	min = find_min(num1,num2,num3);
	diff = max - min;
	printf("���� ū ���� �������� ���� =%f", diff);
}

float find_max(float a, float b, float c)
{
	float max;
	if (a > b)
		if (a > c)
			max = a;
		else
			max = c;
	else
		max = (b > c) ? b : c;
	return max;
}

float find_min(float a, float b, float c)
{
	float min = a;
	if (min > b)
		min = b;
	else if (min > c)
		min = c;

	return min;
}