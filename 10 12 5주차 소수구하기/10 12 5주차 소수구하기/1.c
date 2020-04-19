#include<stdio.h>
#include<math.h>
int is_prime(int n);

void main()
{
	int number;
	while (1)
	{
		printf("소수 판정 숫자 :");
		scanf("%d", &number);

		if (number >= 2)
		{
			if (is_prime(number) == 1)
			{
				printf("%d 는 소수 \n", number);
			}
			else
			{
				printf("%d 는 소수가 아니다.", number);
			}
		}

		else
		{
			printf("fail\n");
			break;
		}
	}
}

int is_prime(int n)
{
	int divider, to;
	to = (int)sqrt((double)n);
	divider = 2;
	while (divider < to)
	{
		if ((n%divider) == 0)
		{
			return 0;
		}
		divider += 1;
	}
	return 1;
}