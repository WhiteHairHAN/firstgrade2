#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#define SIZE 10
#define MAX 1000

void generate_random(int array[]);
void print_array(char *str, int array[]);
void selection_sort(int array[]);
void swap(int *xp, int *yp);
void main(void)
{
	int n, r;
	int data[SIZE];
	srand(time(NULL));	// �� ���� ȣ��
	for (n = 0; n<3; n++)
	{
		generate_random(data);
		print_array("����: ", data); // ���� ���
		selection_sort(data);	    // �������� ����
		print_array("����: ", data); // ���� ���
		printf("\n");
	}
}


void generate_random(int array[])
{
	int n;
	// �迭�� ũ�⸸ŭ
	for (n = 0; n<SIZE; n++)
		// ������ �����Ͽ� �����Ѵ�.
		array[n] = (rand() % MAX) + 1;
}

void print_array(char *str, int array[])
{
	int n;
	printf("%s", str); // �迭 ���� ���.
	for (n = 0; n<SIZE; n++)
		printf("%5d", array[n]);	// �迭 �������
	printf("\n");		// ���� �ݺ� ����
}


void selection_sort(int array[])
{
	int n, m, minindex;			// ���� m �߰�
	for (n = 0; n<SIZE - 1; n++)
	{
		minindex = n;			// �迭�� ���� ��ġ�� �ּҰ����� ����
		for (m = n + 1; m < SIZE; m++)
		
			if (array[minindex] > array[m])
				minindex = m;

			swap(&array[minindex], &array[n]);
		
	}
}

void swap(int *xp, int *yp)
{
	int temp;

	temp = *xp;
	*xp = *yp;
	*yp = temp;
}