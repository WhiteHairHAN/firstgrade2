#include<stdio.h>
int main()
{
	int num;
	printf("ют╥б : ");
	scanf("%d", &num);

	for (int j = 1; j <= num; j++)
	{
		if ((j % 2) == 1)
		{
			printf("%d\n", j);
		}
	}
}