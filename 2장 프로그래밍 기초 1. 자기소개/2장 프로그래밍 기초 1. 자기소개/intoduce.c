#include<stdio.h>
void main()
{
	char depa[20], name[10];
	int grade, year;
	printf("������ �Է��ϼ���\n\n");
	printf("�а�:");
	scanf("%s", &depa);
	printf("�г�:");
	scanf("%d", &grade);
	printf("���г⵵:");
	scanf("%d", &year);
	printf("�̸�");
	scanf("%s", name);

	printf("\n ���� %s %d �г� %d �й� %s �Դϴ�.\n", depa, grade, year, name);
}