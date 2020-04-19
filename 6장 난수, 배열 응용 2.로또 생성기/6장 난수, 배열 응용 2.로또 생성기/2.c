#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void user_check(int arr_user[]);
void generate_lotto(int arr_lotto[]);
int mappingNumber(int arr_user[], int arr_lotto[]);

int main(void)
{
	int arr_lotto[6];
	int arr_user[6];
	int i, win, cnt = 0;

	srand((unsigned)time(NULL));
	user_check(arr_user);
	generate_lotto(arr_lotto);

	printf("\n입력번호");
	for (i = 0; i < 6; i++)
		printf("%d   ", arr_user[i]);
	printf("\n당첨번호");
	for (i = 0; i < 6; i++)
		printf("%d   ", arr_lotto[i]);

	win = mappingNumber(arr_user, arr_lotto);
	printf("\n 당첨번호는 %d 개 입니다.", win);

	return 0;
}

void generate_lotto(int arr_lotto[])
{
	int i, dup, cnt = 0; 

	do {
		arr_lotto[cnt] = rand() % 45 + 1;
		if (cnt > 0)
		{
			for (i = 0; i < cnt; i++)
			{
				if (arr_lotto[i] == arr_lotto[cnt])
				{
					dup++;
				}
			}
		}
		if (dup == 0)
		{
			cnt++;
		}
		else
		{
			dup = 0;
		}
	} while (cnt < 6);

}

void user_check(int arr_user[])
{
	int i;
	int num;

	printf("1~45 사이의 번호를 6개 입력하세요 :");
	for (i = 0; i < 6; i++)
	{
		scanf("%d", &arr_user[i]);
	}
}

int mappingNumber(int arr_user[], int arr_lotto[])
{
	int count;
	int i, j;

	for(i=0; i<6;i++)
		for(j=0;j<6;j++)
			if (arr_user[i] == arr_lotto[i])
			{
				count++;
				break;
			}
	return count;
}