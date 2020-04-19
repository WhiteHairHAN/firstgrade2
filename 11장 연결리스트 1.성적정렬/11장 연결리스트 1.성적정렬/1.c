#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct STUDENT_INFO SINFO;
void insert_node(SINFO *student);
void get_studentinfo();
void print_list();
void delete_list();

SINFO *listhead = NULL;

struct STUDENT_INFO
{
	char id[16];
	char name[16];
	int score;
	struct STUDENT_INFO *next;
};



void main()
{
	get_studentinfo();
	print_list();
	delete_list();
}

void get_studentinfo() 
{
	SINFO student;
	printf("학생 정보를 입력하세요 \n");
	printf("입력을 마치려면 학번에 -1을 넣어라\n\n");

	while (1)
	{
		printf("학번: ");
		scanf("%s", student.id);
		if (strcmp(student.id, "-1") != 0)
		{
			printf("이름: ");
			scanf("%s", student.name);
			printf("성적: ");
			scanf("%s", &student.score);
			insert_node(&student);
			printf("\n");
		}
		else
			break;
	}
}

void insert_node(SINFO *student)
{
	SINFO *search, *previous;
	SINFO *temp = (SINFO *)malloc(sizeof(SINFO));
	strcpy(temp->id, student->id);
	strcpy(temp->name, student->name);
	temp->score = student->score;

	
	search = listhead;
	previous = NULL;

	while (search != NULL)
	{
		if (temp->score < search->score)
		{
			previous = search;
			search = search->next;
		}
		else
			break;
		if (previous == NULL)
		{
			temp->next = listhead;
			listhead = temp;
		}
		else
		{
			temp->next = search;
			previous->next = temp;
		}
		
	}
	
}
void print_list() 
{
	SINFO *search;
	search = listhead;
	printf("\n %16s%16s%6s\n", "학번", "이름", "성적");
	printf("==============================================\n");
	while (search != NULL)
	{
		printf("%16s", search->id);
		printf("%16s", search->name);
		printf("%6d\n", search->score);
		search = search -> next;
	}
}

void delete_list() 
{
	SINFO *temp = listhead;
	while (listhead != NULL)
	{
		listhead = listhead->next;
		free(temp);
		temp = listhead;
	}
}