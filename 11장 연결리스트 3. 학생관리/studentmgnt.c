//studentmgnt.c �ҽ� ����
#include "studentmgnt.h"

SINFO *listhead = NULL;


void main()
{
	char menu = 0;
	read_list();
	while (menu != '7')
	{
		menu = print_menu();
		printf("%c �� ����� �����Ͽ����ϴ�.\n",menu);

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
	printf("ó���� ����� ��ȣ�� �����ϼ���.\n\n");
	printf("1. �ڷ��߰�\n");
	printf("2. ��ϰ˻�\n");
	printf("3. ��ϻ���\n");
	printf("4. �������\n");
	printf("5. ��Ϻ���\n");
	printf("6. �޴�����\n");
	printf("7. ����\n\n");
	printf("���� > ");
	menu = getchar();
	getchar();

	return menu;
}

void add_student()
{
	SINFO *temp;	//�ӽ� ����
	temp = (SINFO *) malloc(sizeof(SINFO));	//������ �Ҵ�
	printf("�����͸� �Է��ϼ���\n");
	printf("�а�: ");	scanf("%s", temp->major);
	printf("�й�: ");	scanf("%s", temp->id);
	printf("�̸�: ");	scanf("%s", temp->name);
	printf("����: ");	scanf("%d", &temp->score);

	insert_node(temp, NULL, listhead);	//����Ʈ�� �߰�

	printf("%s�� �����͸� �����Ͽ����ϴ�.\n\n", temp->name);
	getchar();	//���� ����
}

void insert_node(SINFO *temp, SINFO *previous, SINFO *pos)
{
	if (previous == NULL)     //ó���� ����
	{
		temp->next = pos;
		listhead = temp;
	}
	else        //����Ʈ�� �߰� ���Ŀ� ����
	{
		temp->next = pos;
		previous->next = temp;
	}
}

void print_list()
{
	SINFO *search = listhead;

	printf("\n%-16s%-16s%-16s%-6s\n","�а�","�й�","�̸�","����");
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
	printf("\n�������� �˻��Ͻðڽ��ϱ�?\n");
	printf("1. �й�\n");
	printf("2. �̸�\n\n");
	printf("�˻� ���� > ");
	cond = getchar();

	if (cond == '1')
	{
		printf("\n�й���? "); scanf("%s", key);
		print_node(key, cond);
	}
	else if(cond == '2')
	{
		printf("\n�̸���? "); scanf("%s", key);
		print_node(key, cond);
	}
	else
		printf("\n�˻� ������ Ʋ���ϴ�.\n\n");
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
		printf("\n�˻� ���: ");
		printf("%s ", search->major);
		printf("%s ", search->id);
		printf("%s ", search->name);
		printf("%3d\n\n", search->score);
	}
	else
		printf("\n\n�˻� ���ǿ� �ش��ϴ� �л��� �����ϴ�.\n\n");
}

void sort_menu()
{
	char cond;
	printf("\n�������� �����Ͻðڽ��ϱ�?\n");
	printf("1. �а�\n");
	printf("2. �й�\n");
	printf("3. ����\n");
	printf("���� ���� > ");
	
	cond = getchar();
	if((cond == '1') || (cond == '2') || (cond == '3'))
		sort_list(cond);
	else
		printf("\n�˻� ������ Ʋ���ϴ�.\n\n");

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
		printf("\n�а������� �����Ͽ����ϴ�.\n\n");
	else if(cond == '2')
		printf("\n�й� ������ �����Ͽ����ϴ�.\n\n");
	else
		printf("\n���� ������ �����Ͽ����ϴ�.\n\n");
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
	printf("\n�������� �����Ͻðڽ��ϱ�?\n");
	printf("1.�̸�\n");
	printf("2.�й�\n");
	printf("���� ���� > ");

	cond = getchar();
	getchar();
	if((cond == '1') || (cond == '2'))
		delete_node(cond);
	else
		printf("\n�˻� ������ Ʋ���ϴ�.\n\n");
}

void delete_node(char cond)
{
	int result;
	char name[16], id[16];
	SINFO *search, *previous;

	if(cond == 1)
	{
		printf("\n������ �л��� �̸��� �Է��ϼ���: \n");
		printf("�̸�: ");	scanf("%s", name);	
	}
	else
	{
		printf("\n������ �л��� �й��� �Է��ϼ���: \n");
		printf("�й�: ");	scanf("%s", id);
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
		printf("�л� �����Ͱ� �������� �ʽ��ϴ�.\n");
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
			printf("%s �л��� �����͸� �����Ͽ����ϴ�.\n\n", name);
		else
			printf("%s �й��� �����͸� �����Ͽ����ϴ�.\n\n", id);
	}
}