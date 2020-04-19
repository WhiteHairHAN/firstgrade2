#include<stdio.h>

int perfect_number(int number);
int main(void)
{
	int number, n;
	printf("1000 이하의 완전수 :\n");
	for (number = 1; number <= 1000; number++)
	{
		if (perfect_number(number) == 1)
		{
			printf("%d \n", number);
		}
	}
	return 0;
}

int perfect_number(int number)
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
