#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<Windows.h>

void Swap(int *a, int *b);
void Start();

void PrintArr(int(*arr)[5]);
void ComputerSelect();
void UserSelect();
void SelectedNumber();
int CheckWiner(int(*arr)[5]);

int user[5][5];
int computer[5][5];
int checked[25];
int count;

void main()
{
	int i, j, turn = 0;
	Start();

	do {
		if (turn % 2 == 0)
		{
			system("cls");
			PrintArr(user);
			printf("\n���ڸ� �����ϼ���:");
			UserSelect();
			SelectedNumber();
			system("cls");
			PrintArr(user);
			printf("\n ����ڰ� [%d] �� �����߽��ϴ�.\n ", checked[count - 1]);
			turn++;
		}
		else
		{
			ComputerSelect();
			SelectedNumber();
			printf("��ǻ�Ͱ� [%d] �� �����߽��ϴ�.",checked[count-1]);
			system("pause");
			turn++;
		}
	} while ((CheckWiner(computer) + CheckWiner(user)) == 0);

	system("cls");
	printf("�����:\n");
	PrintArr(user);
	printf("\n ��ǻ�� \n");
	PrintArr(computer);

	if ((CheckWiner(computer) + CheckWiner(user)) == 2)
		printf("���º��Դϴ�.\n");
	else
	{
		if (CheckWiner(computer) == 1)
			printf("��ǻ�Ͱ� �̰���ϴ�.\n");
		else
			printf("����ڰ� �̰���ϴ�.\n");
	}
}

void Start()
{
	int i, j, k;
	int RandArry[25];

	srand(time(NULL));
	for (i = 0; i < 25; i++)
		RandArry[i] = i + 1;

	for (i = 0; i < 25; i++)
		Swap(&RandArry[i], &RandArry[rand() % 25]);
	for (i = 0, k = 0; j < 5; i++)
		for (j = 0; j < 5; j++)
			computer[i][j] = RandArry[k++];

	for (i = 0; i < 25; i++)
		Swap(&RandArry[i], &RandArry[rand() % 25]);
	for (i = 0, k = 0; j < 5; i++)
		for (j = 0; j < 5; j++)
			user[i][j] = RandArry[k++];

	for (i = 0; i < 25; i++)
		checked[i] = 0;
	count = 0;
}

void Swap(int *a, int *b)
{
	int temp;
	temp = *a;
	*a = *b;
	*b = temp;
}

void PrintArr(int(*arr)[5])
{
	int i, j;
	for (i = 0; i < 5; i++)
	{
		for (j = 0; j < 5; j++)
		{
			if (arr[i][j] != -1)
				printf("%5d", arr[i][j]);
			else
				printf("%5c", 'X');
		}
		printf("\n");
	}
}

void ComputerSelect()
{
	int i, ComputerSelectNum, flag;
	while (1)
	{
		ComputerSelectNum = (rand() % 25) + 1;
		flag = 0;

		for (i = 0; i < count; i++)
			if (checked[i] == ComputerSelectNum)
				flag = 1;

		if (flag == 0)
		{
			checked[count++] = ComputerSelectNum;
			break;
		}
	}
}

void UserSelect()
{
	int i, UserSelectNum, flag;

	while (1)
	{
		scanf_s("%d", &UserSelectNum);
		flag = 0;

		if (UserSelectNum < 0 || UserSelectNum >25)
			flag = 1;

		for (i = 0; i < count; i++)
			if (checked[i] == UserSelectNum)
				flag = 1;

		if (flag == 0)
		{
			checked[count++] = UserSelectNum;
			break;
		}
		printf("\n �˸��� ���ڸ� �����ϼ���:");
	}
}

void SelectedNumber()
{
	int i, j;
	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (computer[i][j] == checked[count - 1])
				computer[i][j] = -1;

	for (i = 0; i < 5; i++)
		for (j = 0; j < 5; j++)
			if (user[i][j] == checked[count - 1])
				user[i][j] = -1;
}

int CheckWiner(int(*arr)[5])
{
	int i, j, bingo, Win = 0;

	for (i = 0; i < 5; i++)
	{
		bingo = 0;
		for (j = 0; j < 5; j++)
			if (arr[i][j] == -1)
				bingo++;
		if (bingo == 5)
		{
			Win = 1;
			break;
		}
	}

	for (j = 0; j < 5; j++)
	{
		bingo = 0;
		for (i = 0; i < 5; i++)
			if (arr[i][j] == -1)
				bingo++;
		if (bingo == 5)
		{
			Win = 1;
			break;
		}
	}

	bingo = 0;
	for (i = 0, j = 0; i < 5 && j < 5; i++, j++)
	{
		if (arr[i][j] == -1)
			bingo++;
		if (bingo == 5)
			Win = 1;
	}

	bingo = 0;
	for (i = 0, j = 4; i<5 && j>-1; i++, j--)
	{
		if (arr[i][j] == -1)
			bingo++;
		if (bingo == 5)
			Win = 1;
	}
	return Win;
}
