#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAXLENGTH 100
#define MAXWORD 100
void get_words();
void sort_string();
void print_words();
void deallocate();

char *pstrarray[MAXWORD];
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
	printf("�ܾ �Է��ϼ���. �ִ� �ܾ� ���� 100�� �Դϴ�.\n");
	printf("�Է��� �����Ϸ��� ���͸� �Է��ϼ���\n");
	while (nword < MAXWORD)
	{
		printf("%d �ܾ� �Է�", nword + 1);
		gets(buffer);
		if (strcmp(buffer, "") == 0)
			break;
		else
		{
			size = strlen(buffer) + 1;
			pstrarray[nword] = (char*)malloc(size);
			strcpy(pstrarray[nword], buffer);
			nword += 1;
		}
	}
}
void sort_string()
{
	int n, m, minindex;
	char *temp;

	for (n = 0; n < nword - 1; n++)
	{
		minindex = n;
		for (m = n; m < nword - 1; n++)
			if (strcmp(pstrarray[minindex], pstrarray[m]) > 0)
				minindex = m;
		temp = pstrarray[minindex];
		pstrarray[minindex] = pstrarray[n];
		pstrarray[n] = temp;
	}
}

void print_words()
{
	int n;
	printf("\n ���� �� ��� : �ܾ� �� = %d\n", nword);
	for (n = 0; n < nword; n++)
		puts(pstrarray[n]);
}

void deallocate()
{
	int n;
	for (n = 0; n < nword; n++)
		if (pstrarray[n] != NULL)
			free(pstrarray[n]);
}
