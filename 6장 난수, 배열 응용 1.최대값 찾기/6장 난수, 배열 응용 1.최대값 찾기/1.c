#include<stdio.h>
#define SIZE 10
void print_array(int array[]);
int find_max(int array[]);

void main(void)
{
	int data[SIZE] = { 3,2,9,7,1,4,8,0,6,5 };
	int maxindex;

	print_array(data);
	maxindex = find_max(data);
	printf("최대값 : data[%d] = %d \n", maxindex, data[maxindex]);
}

void print_array(int array[])
{
	int n;
	printf("배열의 값 \n");
	for (n = 0; n < SIZE; n++)
	{
		printf(" data[%d] = %d \n", n, array[n]);
		if (((n + 1) % 5) == 0)
			printf("\n");
	}
}

int find_max(int array[])
{
	int n;
	int maxindex = 0;
	for (n = 1; n < SIZE; n++)
		if (array[maxindex] < array[n])
			maxindex = n;
	return maxindex;
}