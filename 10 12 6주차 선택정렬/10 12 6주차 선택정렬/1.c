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
	srand(time(NULL));	// 한 번만 호출
	for (n = 0; n<3; n++)
	{
		generate_random(data);
		print_array("원본: ", data); // 원본 출력
		selection_sort(data);	    // 오름차순 정렬
		print_array("정렬: ", data); // 정렬 출력
		printf("\n");
	}
}


void generate_random(int array[])
{
	int n;
	// 배열의 크기만큼
	for (n = 0; n<SIZE; n++)
		// 난수를 생성하여 저장한다.
		array[n] = (rand() % MAX) + 1;
}

void print_array(char *str, int array[])
{
	int n;
	printf("%s", str); // 배열 제목 출력.
	for (n = 0; n<SIZE; n++)
		printf("%5d", array[n]);	// 배열 원소출력
	printf("\n");		// 다음 반복 구별
}


void selection_sort(int array[])
{
	int n, m, minindex;			// 변수 m 추가
	for (n = 0; n<SIZE - 1; n++)
	{
		minindex = n;			// 배열의 시작 위치를 최소값으로 가정
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