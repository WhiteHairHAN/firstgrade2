#define DATANUM 100
#define FILENAME "난수파일.txt"

#include<stdio.h>
#include<string.h>
#include<time.h>
#include<stdlib.h>

void make_input_file();
void read_file(int input_data[]);
void Binary_search(int keys[], int find_key, int left, int right, int cnt);
void Linear_search(int keys[], int find_key, int n);

void main()
{
	int input_data[DATANUM];
	int i, j, temp, want_to_find = 0; , select = 0;

	make_input_file();

	read_file(input_data);

	printf("찾고싶은 숫자 입력(0~99)");
	scanf("%d", &want_to_find);

	printf("탐색 방식 설정 (1. 이진, 2.선형) :");
	scnaf("%d", &select);
}