#include<stdio.h>
void printf_array(char *str, int array[], int size);

void main(void)
{
	int data[] = {1, 2, 3, 4, 5, 6, 7};
	int size = 7;
	int index, key = 1;


	print_array("����:", data, size);
	while (key > 0)
	{
		printf("�˻��� ���� �Է��ϼ���:");
		scanf("%d", &key);
		if (key > 0)
		{

			printf("%d�� Ž���մϴ�.", key);
		}
	}
	pritnf("���α׷��� �����մϴ�.\n\n");
}