#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXWORD 100
#define MAXLENGTH 100

void get_words();
void sort_string();
void print_words();
void deallocate();

char *pst[MAXWORD];
int nword;

void main()
{
	get_words();
	sort_string();
	print_words();
	deallocate();
}

void get_words()
{
	char buffer[100];
	int size;

	nword = 0;
	printf("�ܾ �Է��ϼ��� �ִ� �ܾ���� 100���Դϴ�.\n");
	printf("�Է��� �����Ϸ��� ���͸� �Է��ϼ��� \n\n");

	while (nword < MAXLENGTH)
	{
		printf("%d �ܾ��Է�", nword + 1);
		gets(buffer);
		if (strcmp(buffer, "") == 0)
			break;
		else
		{
			size = strlen(buffer) + 1;
			pst[nword] = (char*)malloc(size);
			strcpy(pst[nword], buffer);
			nword += 1;
		}
	}
}

void deallocate()
{
	int n;
	for (n = 0; n < nword; n++)
		if (pst[n] != NULL)
			free(pst[n]);
}

void print_words()
{
	int n;
	printf("\n ���� �� ��� : �ܾ�� =%d\n", nword);
	for (n = 0; n < nword; n++)
		puts(pst[n]);
}

void sort_string()
{
	int n, m, minindex;
	char *temp;
	
	for (n = 0; n < nword; n++)
	{
		minindex = n;
		for (m = n; m < nword; m++)
			if (strcmp(pst[minindex], pst[m]) > 0)
				minindex = m;
		temp = pst[minindex];
		pst[minindex] = pst[n];
		pst[n] = temp;
	}
}