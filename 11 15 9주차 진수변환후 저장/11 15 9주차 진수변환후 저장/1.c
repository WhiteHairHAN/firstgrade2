#include<stdio.h>
void main()
{
	int num_tmp;
	FILE *fp;

	printf("������ �Է� : ");
	scanf("%d", &num_tmp);

	printf("�Էµ� ���ڸ� 8������ ��ȯ�ϸ� %o\n", num_tmp);
	printf("�Էµ� ���ڸ� 16������ ��ȯ�ϸ� %x\n", num_tmp);

	fp = fopen("result.txt", "a");
	fprintf(fp,"�Է¹��� ���� : %d 8������ ǥ�� %o", num_tmp, num_tmp);
	fputc('\n', fp);
	fprintf(fp, " 16������ ǥ�� %x", num_tmp);
	fputc("\n", fp);
	fclose(fp);
}