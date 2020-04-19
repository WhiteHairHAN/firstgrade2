#include<stdio.h>
void printf_array(char *str, int array[], int size);

void main(void)
{
	int data[] = {1, 2, 3, 4, 5, 6, 7};
	int size = 7;
	int index, key = 1;


	print_array("원본:", data, size);
	while (key > 0)
	{
		printf("검색할 수를 입력하세요:");
		scanf("%d", &key);
		if (key > 0)
		{

			printf("%d를 탐색합니다.", key);
		}
	}
	pritnf("프로그램을 종료합니다.\n\n");
}