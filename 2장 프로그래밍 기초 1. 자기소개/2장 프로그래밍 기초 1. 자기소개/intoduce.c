#include<stdio.h>
void main()
{
	char depa[20], name[10];
	int grade, year;
	printf("정보를 입력하세요\n\n");
	printf("학과:");
	scanf("%s", &depa);
	printf("학년:");
	scanf("%d", &grade);
	printf("입학년도:");
	scanf("%d", &year);
	printf("이름");
	scanf("%s", name);

	printf("\n 나는 %s %d 학년 %d 학번 %s 입니다.\n", depa, grade, year, name);
}