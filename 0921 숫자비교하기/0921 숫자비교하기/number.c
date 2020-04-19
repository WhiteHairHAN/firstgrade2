#include<stdio.h>

float find_max(float a, float b, float c);
float find_min(float a, float b, float c);

void main()
{
	float num1, num2, num3, max, min, diff;
	printf("세수를 입력하세여\n");
	printf("첫번째수 :");
	scanf("%f", &num1);
	printf("두번째수 :");
	scanf("%f", &num2);
	printf("세번째수 :");
	scanf("%f", &num3);

	max = find_max(num1,num2,num3);
	min = find_min(num1,num2,num3);
	diff = max - min;
	printf("가장 큰 수와 작은수의 차이 =%f", diff);
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