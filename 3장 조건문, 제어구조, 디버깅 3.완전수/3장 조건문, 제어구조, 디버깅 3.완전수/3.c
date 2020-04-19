#include<stdio.h>
void perfect_num(int number);
void main(void)
{
	int number;
	printf("1000이하의 완전수를 구해봅니다.\n");
	for (number = 1; number <= 1000; number++)
	{
		if (perfect_num(number) == 1)
			printf(" %d \n", number);
	}
	return 0;
}

void perfect_num(int number)
{
	int i, sum;
	sum = 0;
	for (i = 1; i < number; i++)
	{
		if (number%i == 0)
			sum = sum + i;
	}
	if (sum == number)
		return 1;
	else
		return 0;
}