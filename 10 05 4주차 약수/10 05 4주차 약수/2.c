#include<stdio.h>

void main()
{
	int number;
	while (1)
	{
		printf("약수를 구할 정수를 입력하세요(1이하의 수면 종료):");
		scanf("%d", &number);
		if (number >= 2)
		{
			printf("%d 에 대한 약수를 구합니다. \n", number);
			print_divisor(number);
		}
		else
		{
			printf("%d에 대한 약수를 구할 수 없습니다.\n", number);
			printf("프로그램을 종료합니다\n");
			break;
		}
		printf("\n");
	}
}

int print_divisor(int value)
{
	int n, remains;
	printf("%d 의 약수 :", value);
	for (n = 2; n <= value; n++)
	{
		remains = value %n;
		if (remains == 0)
			printf("%d ", n);
	}
	printf("\n");
}