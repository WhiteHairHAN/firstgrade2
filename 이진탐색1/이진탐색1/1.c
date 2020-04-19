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
		printf("배열입력 %d (오름차순)", i + 1);
		scanf("%d", &inputarr);
		arr[i] = inputarr;
	}
	printf("이진탐색\n");
	printf("찾고자하는 수 입력 :");
	scanf("%d", &inputnum);

	ret = bi(SIZE, arr, inputnum);
	if (ret == 1)
	{
		printf("%d 탐색실패\n", inputnum);
	}
	else
		printf("%d째 인덱스에서 %d 탐색성공!\n", ret + 1, arr[ret]);
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
