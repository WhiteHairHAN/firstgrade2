#include<stdio.h>
#include<string.h>

#define STU_NUMBER 1
#define REG_NUMBER 2

struct student {
	int type;
	union {
		int stu_number;
		char reg_number[15];
	}id;
	char name[20];
};

void print(struct students)
{
	switch (s.type)
	{
	case STU_NUMBER:
		printf("ÇÐ¹ø %d ")
	}
}