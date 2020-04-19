#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void generate_random(int array[], int size);
void print_array(char *str, int array[], int size);
void bubble_sort(int array[], int size);
void swap(int *xp, int *yp);

void main(void)
{
	int *data, size;
	srand(time(NULL));
	printf("배열의 크기를 입력하세요 :");
	scanf("%d", &size);
	data = (int *)malloc(sizeof(int)*size);

	generate_random(data, size);
	print_array("원본", data, size);

	print_array("정렬", data, size);
	free(data);
	bubble_sort(data, size);
}


void generate_random(int array[], int size)
{
	int n;
	for (n = 0; n < size; n++)
		array[n] = (rand() % 100) + 1;
}

void print_array(char *str, int array[], int size)
{
	int n;
	printf("%s %d\n", str, size);
	for (n = 0; n < size; n++)
	{
		printf("%5d", array[n]);
		if ((n + 1) % 10 == 0)
			printf("\n");
	}
	printf("\n");
}

void bubble_sort(int array[], int size)
{
	int n, m;
	for (n = 0; n<size - 1; n++)
		for (m = 0; m<size - n - 1; m++)	
			if (array[m] > array[m + 1])
				swap(&array[m], &array[m + 1]);
}

void swap(int *xp, int *yp)
{
	int temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}