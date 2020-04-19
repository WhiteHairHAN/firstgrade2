#include <stdio.h>
#include <stdlib.h>    // malloc, free 함수가 선언된 헤더 파일

struct NODE {             // 연결 리스트의 노드 구조체
	struct NODE *next;    // 다음 노드의 주소를 저장할 포인터
	int data;             // 데이터를 저장할 멤버
};

void addFirst(struct NODE *target, int data) // 기준 노드 뒤에 노드를 추가하는 함수
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
	struct NODE *head = (struct NODE *)malloc(sizeof(struct NODE));    // 머리 노드 생성
																	   // 머리 노드는 데이터를 저장하지 않음

	struct NODE *curr = NULL;


	head->next = NULL;
	/*
	addFirst(head, 10);	//머리 노드 뒤에 새 노드 추가
	addFirst(head, 30);
	addFirst(head, 20);
	addFirst(head, 15);
	addFirst(head, 35);
	addFirst(head, 8);
	*/

	addSort(head, 10);	//머리 노드 뒤에 새 노드 추가
	addSort(head, 30);
	addSort(head, 20);
	addSort(head, 15);
	addSort(head, 35);
	addSort(head, 8);
	//removeFirst(head);

	curr = head->next;
	while (curr != NULL)               // 포인터가 NULL이 아닐 때 계속 반복
	{
		printf("%d\n", curr->data);    // 현재 노드의 데이터 출력
		curr = curr->next;             // 포인터에 다음 노드의 주소 저장
	}


	curr = head->next;
	while (curr != NULL)
	{
		struct NODE *next = curr->next;
		free(curr);
		curr = next;
	}

	free(head);     // 머리 노드 메모리 해제

	return 0;
}



