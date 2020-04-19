#include <stdio.h>
#include <stdlib.h>    // malloc, free �Լ��� ����� ��� ����

struct NODE {             // ���� ����Ʈ�� ��� ����ü
	struct NODE *next;    // ���� ����� �ּҸ� ������ ������
	int data;             // �����͸� ������ ���
};

void addFirst(struct NODE *target, int data) // ���� ��� �ڿ� ��带 �߰��ϴ� �Լ�
{
	struct NODE *newNode = (struct NODE *) malloc(sizeof(struct NODE));
	newNode->next = target->next;
	newNode->data = data;
}

void addSort(struct NODE *target, int data)
{
	struct NODE *curr, *prev;
	struct NODE *newNode = (struct NODE *)malloc(sizeof(struct NODE));
	newNode->data = data;

	if (target->next == NULL)
	{
		target->next = newNode;
		newNode->next = NULL;
	}
	else
	{
		prev = curr = target;
		while (curr != NULL)
		{
			if (data < curr->data)
			{
				prev->next = newNode;
				newNode->next = curr;
				break;
			}
			else
			{
				prev = curr;
				curr = curr->next;
				if (curr == NULL)
				{
					prev->next = newNode;
					newNode->next = NULL;
					break;
				}
			}
		}
	}
}

void removeFirst(struct NODE *target)
{
	struct NODE *removeNode = target->next;
	target->next = removeNode->next;

	free(removeNode);
}


int main()
{
	struct NODE *head = (struct NODE *)malloc(sizeof(struct NODE));    // �Ӹ� ��� ����
																	   // �Ӹ� ���� �����͸� �������� ����

	struct NODE *curr = NULL;


	head->next = NULL;
	/*
	addFirst(head, 10);	//�Ӹ� ��� �ڿ� �� ��� �߰�
	addFirst(head, 30);
	addFirst(head, 20);
	addFirst(head, 15);
	addFirst(head, 35);
	addFirst(head, 8);
	*/

	addSort(head, 10);	//�Ӹ� ��� �ڿ� �� ��� �߰�
	addSort(head, 30);
	addSort(head, 20);
	addSort(head, 15);
	addSort(head, 35);
	addSort(head, 8);
	//removeFirst(head);

	curr = head->next;
	while (curr != NULL)               // �����Ͱ� NULL�� �ƴ� �� ��� �ݺ�
	{
		printf("%d\n", curr->data);    // ���� ����� ������ ���
		curr = curr->next;             // �����Ϳ� ���� ����� �ּ� ����
	}


	curr = head->next;
	while (curr != NULL)
	{
		struct NODE *next = curr->next;
		free(curr);
		curr = next;
	}

	free(head);     // �Ӹ� ��� �޸� ����

	return 0;
}



