#include<stdio.h>
#define MAX_SIZE 5

void main()
{
	int arr[MAX_SIZE];
	int i;

	for (int i = 0; i < MAX_SIZE; i++)
	{
		printf("arr[%d] 의 값을 입력하세요 :", i);
		scanf("%d", &arr[i]);
	}
	printf("\n\n 출력 \n\n");

	for (int j = 1; j <= MAX_SIZE; j++)
	{
		printf("%d\t %d\n", arr[j - 1], arr[MAX_SIZE - j]);
	}
}