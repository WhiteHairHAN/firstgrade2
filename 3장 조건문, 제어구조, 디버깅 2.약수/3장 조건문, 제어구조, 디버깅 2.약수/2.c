#include<stdio.h>
void point_divisor(int value);
void main()
{
	int number;
	printf("정수를 입력하시오 :");
	scanf("%d", &number);
	if (number >= 2)
	{
		printf("%d 에 대한 약수를 구합니다.\n", number);
		point_divisor(number);
	}
	else
		printf("약수를 구할 수 없습니다.\n");
		printf("\n");
}

void point_divisor(int value)
{
	int n, remains;
	printf("%d 의 약수 : ", value);
	for (n = 2; n <= value; n++)
	{
		remains = value %n;
		if (remains == 0)
			printf("%d ", n);
	}
	printf("\n");
}