#include <stdio.h>
#include <string.h>
#include <malloc.h>

//#define _CRT_SECURE_NO_WARNINGS
#pragma warning(disable:4996)

typedef struct STUDENT_INFO SINFO;

struct STUDENT_INFO
{
	char major[32];
	char id[16];
	char name[16];
	int score;
	struct STUDENT_INFO *next;
};


char print_menu();

void add_student();
void insert_node(SINFO *temp, SINFO *previous, SINFO *pos);
void print_list();
void delete_list();

void write_list();
void read_list();

void search_menu();
void print_node(char *, char);

void sort_menu();
void sort_add(SINFO *, char);
void sort_list(char);
void delete_node(char);
void delete_menu();

