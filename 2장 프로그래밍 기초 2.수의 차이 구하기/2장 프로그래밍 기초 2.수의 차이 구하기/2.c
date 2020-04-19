#include<stdio.h>
float find_max(float a, float b, float c);
float find_min(float a, float b, float c);
void main()
{
	float x, y, z;
	float max, min, diff;
	printf("세개의 수를 입력하시오");
	printf("첫번째 수 : ");
	scanf("%f", &x);
	printf("두번째 수 : ");
	scanf("%f", &y);
	printf("세번째 수 : ");
	scanf("%f", &z);
	max = find_max(x,y,z);
	min = find_min(x, y, z);
	diff = max - min;
	printf("\n가장큰수와 작은수의 차이 = %f\n\n,", diff);
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