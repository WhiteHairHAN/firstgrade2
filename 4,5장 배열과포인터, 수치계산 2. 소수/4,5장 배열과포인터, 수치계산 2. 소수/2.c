#include<stdio.h>
#include<math.h>

int is_prime(int n);

int main()
{
	int number;
	int a;
	while (1)
	{
		printf("소수를 판정할 정수를 입력하세요 ( 1이하의 수이면 종료)");
		scanf("%d", &number);
		if (number >= 2)
		{
			printf("%d 에 대한 소수를 판정합니다.", number);
			a = is_prime(number);
			if (a == 1)
				printf("소수입니다.\n");
			else
				printf("소수가 아닙니다.\n");
		}
		else
			printf("프로그램을 종료합니다.");
	}
	return 0;
}
// 방법 1 오류 발생;
/*
int is_prime(int n)
{
	int divider, to;

	to = (int)sqrt((double)n);
	divider = 2;
	while (divider <= to)
	{
		if ((n%divider) == 0);
		{
			return 0;
		}
		divider += 1;
	}
	return 1;
}*/

int is_prime(int n)
{
	int divider, to;
	int prime = 1;

	to = (int)sqrt((double)n);
	divider = 2;
	while (divider  <= to)
	{
		if ((n%divider) == 0)
		{
			prime = 0;
			break;
		}
		divider += 1;
	}
	return prime;
}
