#include<stdio.h>
float find_max(float a, float b, float c);
float find_min(float a, float b, float c);
void main()
{
	float x, y, z;
	float max, min, diff;
	printf("������ ���� �Է��Ͻÿ�");
	printf("ù��° �� : ");
	scanf("%f", &x);
	printf("�ι�° �� : ");
	scanf("%f", &y);
	printf("����° �� : ");
	scanf("%f", &z);
	max = find_max(x,y,z);
	min = find_min(x, y, z);
	diff = max - min;
	printf("\n����ū���� �������� ���� = %f\n\n,", diff);
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
	if (min > c)
		min = c;
	return min;
}