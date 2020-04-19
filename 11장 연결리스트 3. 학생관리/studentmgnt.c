//studentmgnt.c 소스 파일
#include "studentmgnt.h"

SINFO *listhead = NULL;


void main()
{
	char menu = 0;
	read_list();
	while (menu != '7')
	{
		menu = print_menu();
		printf("%c 번 기능을 선택하였습니다.\n",menu);

		switch(menu)
		{
		case '1': add_student(); break;
		case '2': search_menu(); break;
		case '3': delete_menu(); break;
		case '4': sort_menu();  break;
		case '5': print_list(); break;
		case '6': break;
		default: break;
		}		
	}

	write_list();

	delete_list();

	return ;
}

void delete_list()
{
	SINFO *temp;

	temp = listhead;
	while(listhead != NULL)
	{
		listhead = listhead->next;
		free(temp);
		temp = listhead;
	}
}


char print_menu()
{
	char menu;
	printf("처리할 기능의 번호를 선택하세요.\n\n");
	printf("1. 자료추가\n");
	printf("2. 목록검색\n");
	printf("3. 목록삭제\n");
	printf("4. 목록정렬\n");
	printf("5. 목록보기\n");
	printf("6. 메뉴보기\n");
	printf("7. 종료\n\n");
	printf("선택 > ");
	menu = getchar();
	getchar();

	return menu;
}

void add_student()
{
	SINFO *temp;	//임시 변수
	temp = (SINFO *) malloc(sizeof(SINFO));	//기억장소 할당
	printf("데이터를 입력하세요\n");
	printf("학과: ");	scanf("%s", temp->major);
	printf("학번: ");	scanf("%s", temp->id);
	printf("이름: ");	scanf("%s", temp->name);
	printf("성적: ");	scanf("%d", &temp->score);

	insert_node(temp, NULL, listhead);	//리스트에 추가

	printf("%s의 데이터를 저장하였습니다.\n\n", temp->name);
	getchar();	//엔터 제거
}

void insert_node(SINFO *temp, SINFO *previous, SINFO *pos)
{
	if (previous == NULL)     //처음에 연결
	{
		temp->next = pos;
		listhead = temp;
	}
	else        //리스트의 중간 이후에 연결
	{
		temp->next = pos;
		previous->next = temp;
	}
}

void print_list()
{
	SINFO *search = listhead;

	printf("\n%-16s%-16s%-16s%-6s\n","학과","학번","이름","성적");
	printf("==========================================================================\n");
	while(search != NULL)
	{
		printf("%-16s",search->major);
		printf("%-16s",search->id);
		printf("%-16s",search->name);
		printf("%-6d\n",search->score);
		search = search->next;
	}
	printf("\n");
}

void write_list()
{
	SINFO *temp;
	FILE *fp;
	if((fp = fopen("student.dat","wb")) != NULL)
	{
		temp = listhead;
		while(temp != NULL)
		{
			fwrite(temp, sizeof(SINFO), 1, fp);
			temp = temp->next;
		}
		fclose(fp);
	}
}

void read_list()
{
	SINFO *temp;
	FILE *fp;
	int count;
	if((fp = fopen("student.dat","rb")) != NULL)
	{
		do
		{
			temp = (SINFO *)malloc(sizeof(SINFO));
			count = fread(temp, sizeof(SINFO), 1, fp);
			if(count != 0)
				insert_node(temp, NULL,listhead);
		} while(count != 0);
		fclose(fp);
	}
}

void search_menu()
{
	char key[32], cond;
	printf("\n무엇으로 검색하시겠습니까?\n");
	printf("1. 학번\n");
	printf("2. 이름\n\n");
	printf("검색 조건 > ");
	cond = getchar();

	if (cond == '1')
	{
		printf("\n학번은? "); scanf("%s", key);
		print_node(key, cond);
	}
	else if(cond == '2')
	{
		printf("\n이름은? "); scanf("%s", key);
		print_node(key, cond);
	}
	else
		printf("\n검색 조건이 틀립니다.\n\n");
	getchar();
}

void print_node(char *key, char cond)
{
	SINFO *search = listhead;
	int result;

	while (search != NULL)
	{
		if (cond == '1')
			result = strcmp(search->id, key);
		else
			result = strcmp(search->name, key);
		if (result == 0)
			break;
		search = search->next;
	}

	if (search != NULL)
	{
		printf("\n검색 결과: ");
		printf("%s ", search->major);
		printf("%s ", search->id);
		printf("%s ", search->name);
		printf("%3d\n\n", search->score);
	}
	else
		printf("\n\n검색 조건에 해당하는 학생이 없습니다.\n\n");
}

void sort_menu()
{
	char cond;
	printf("\n무엇으로 정렬하시겠습니까?\n");
	printf("1. 학과\n");
	printf("2. 학번\n");
	printf("3. 점수\n");
	printf("정렬 조건 > ");
	
	cond = getchar();
	if((cond == '1') || (cond == '2') || (cond == '3'))
		sort_list(cond);
	else
		printf("\n검색 조건이 틀립니다.\n\n");

	getchar();
}

void sort_list(char cond)
{
	SINFO *oldlist, *temp;
	oldlist = listhead;
	listhead = NULL;

	while(oldlist != NULL)
	{
		temp = oldlist;
		oldlist = oldlist->next;
		sort_add(temp, cond);
	}

	if(cond == '1')
		printf("\n학과순으로 정렬하였습니다.\n\n");
	else if(cond == '2')
		printf("\n학번 순으로 정렬하였습니다.\n\n");
	else
		printf("\n점수 순으로 정렬하였습니다.\n\n");
}

void sort_add(SINFO *temp, char cond)
{
	int result;
	SINFO *search, *previous;
	search = listhead;
	previous = NULL;

	while (search != NULL)
	{
		if (cond == '1')
			result = strcmp(temp->major, search->major);
		else if (cond == '2')
			result = strcmp(temp->id, search->id);
		else
		{
			result = temp->score < search->score ? 1 : -1;
		}

		if (result > 0)
		{
			previous = search;
			search = search->next;
		}
		else
			break;
	}
	insert_node(temp, previous, search);
}

void delete_menu()
{
	char cond;
	printf("\n무엇으로 삭제하시겠습니까?\n");
	printf("1.이름\n");
	printf("2.학번\n");
	printf("삭제 조건 > ");

	cond = getchar();
	getchar();
	if((cond == '1') || (cond == '2'))
		delete_node(cond);
	else
		printf("\n검색 조건이 틀립니다.\n\n");
}

void delete_node(char cond)
{
	int result;
	char name[16], id[16];
	SINFO *search, *previous;

	if(cond == 1)
	{
		printf("\n삭제할 학생의 이름을 입력하세요: \n");
		printf("이름: ");	scanf("%s", name);	
	}
	else
	{
		printf("\n삭제할 학생의 학번을 입력하세요: \n");
		printf("학번: ");	scanf("%s", id);
	}
	getchar();
	
	search = listhead;
	previous = NULL;
	while (search != NULL)
	{
		if (cond == 1)
			result = strcmp(name, search->name);
		else
			result = strcmp(id, search->id);

		if (result != 0)
		{
			previous = search;
			search = search->next;
		}
		else
			break;
	}

	if (search == NULL)
	{
		printf("학생 데이터가 존재하지 않습니다.\n");
	}
	else
	{
		if (previous == NULL)
		{
			listhead = search->next;
			free(search);
		}
		else
		{
			previous->next = search->next;
			free(search);
		}
		if(cond == 1)
			printf("%s 학생의 데이터를 삭제하였습니다.\n\n", name);
		else
			printf("%s 학번의 데이터를 삭제하였습니다.\n\n", id);
	}
}