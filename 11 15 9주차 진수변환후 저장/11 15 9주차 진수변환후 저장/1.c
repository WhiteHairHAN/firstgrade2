#include<stdio.h>
void main()
{
	int num_tmp;
	FILE *fp;

	printf("십진수 입력 : ");
	scanf("%d", &num_tmp);

	printf("입력된 숫자를 8진수로 변환하면 %o\n", num_tmp);
	printf("입력된 숫자를 16진수로 변환하면 %x\n", num_tmp);

	fp = fopen("result.txt", "a");
	fprintf(fp,"입력받은 숫자 : %d 8진수로 표현 %o", num_tmp, num_tmp);
	fputc('\n', fp);
	fprintf(fp, " 16진수로 표현 %x", num_tmp);
	fputc("\n", fp);
	fclose(fp);
}