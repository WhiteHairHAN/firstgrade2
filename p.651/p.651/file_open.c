#include<stdio.h>
int main(void)
{
	FILE *fp = NULL;
	fp = fopen("samlpe.txt", "w");
	if (fp == NULL)
		printf("���Ͽ��� ����\n");
	else
		printf("���� ���� ����\n");
	fclose(fp);
	return 0;
}