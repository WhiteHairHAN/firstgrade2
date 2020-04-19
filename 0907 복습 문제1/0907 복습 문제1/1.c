#include<stdio.h>
int main()
{
	int num, e = 0, o = 0;

	printf("ют╥б : ");
	scanf("%d", &num);
	for (int j = 1; j <= num; j++)
	{
		if ((j % 2) == 0)
		{
			if (e == 0)
			{
				e = j;
			}
			else
			{
				e *= j;
			}
		}
		else
		{
			o += j;
		}
	}

	printf("%d\t%d\t", e, o);
}