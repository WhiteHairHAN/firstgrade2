#include<stdio.h>
#define SIZE 6

int bi(int input, int *arr1, int inputnum2);

int main(void)
{
	int inputnum;
	int inputarr;
	int arr[SIZE];
	int i;
	int ret;

	for (i = 0; i < SIZE; i++)
	{
		printf("�迭�Է� %d (��������)", i + 1);
		scanf("%d", &inputarr);
		arr[i] = inputarr;
	}
	printf("����Ž��\n");
	printf("ã�����ϴ� �� �Է� :");
	scanf("%d", &inputnum);

	ret = bi(SIZE, arr, inputnum);
	if (ret == 1)
	{
		printf("%d Ž������\n", inputnum);
	}
	else
		printf("%d° �ε������� %d Ž������!\n", ret + 1, arr[ret]);
	return 0;
}

int bi(int input, int *arr1, int inputnum2)
{
	int low = 0;
	int high = input - 1;
	int mid;

	while (low <= high)
	{
		mid = (low + high) / 2;
		if (inputnum2 == arr1[mid])
			return mid;
		else if (inputnum2 < arr1[mid])
			high = mid - 1;
		else
			low = mid + 1;
	}
	//return -1;
}
