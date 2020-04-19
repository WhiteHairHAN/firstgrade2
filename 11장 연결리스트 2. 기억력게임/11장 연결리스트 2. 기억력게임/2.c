#include<stdio.h>
#include<conio.h>  //getch �� putch �Լ� ����
#include<time.h> // time �Լ�����
#include<windows.h>  // SetConsoleCursorPosition �Լ�����

#define ESC 0x1b  //ESC�� �ƽ�Ű�ڵ�
#define ENTER 0x0d // ����Ű�� �ƽ�Ű�ڵ� ���� 
void initailize();  //���� �ʱ�ȭ �Լ�
void gotoxy(int, int); // Ŀ���� ȭ���� x,y��ǥ�� �ű�� �Լ� ����
void cursor_off(); // ȭ�鿡�� Ŀ���� �����ϴ� �Լ� ����
void sleep(long wait);  //�ð������Լ� ����
void clear_screen();  // ��ũ�� Ŭ���� �Լ�
void play_game();  //������ �����ϴ� �Լ�����
void display_screen();  // ������ ����Լ�
void clear_list();
char get_alphabet(); // ������ ���� �Լ� ����
char alphalist= NULL;
int check_node(int x, int y);

struct ALPHA_NODE
{
	int x;
	int y;
	char alpha;
	struct ALPHA_NODE *next;
};

struct ALPHA_NODE alphalist = NULL;

void main()
{
	char ch = 0;
	initailize(); //���� �ʱ�ȭ
	while (ch != ESC)
	{
		gotoxy(0, 24);  // Ŀ���� ������ �������� �ű��, �ȳ��� ���
		printf("������ �����Ϸ��� ����, �����Ϸ��� ESC �� ��������");
		ch = _getch(); // Ű�� �Է��Ѵ�.
		if (ch == ENTER)
		{
			gotoxy(0, 24);
			printf("���� :                                               ");
			play_game();
		}
		clear_screen(); //ȭ���� �����.
		sleep(1000); //1�ʰ�����Ѵ�.
	}
	clear_list();
}

void initailize()
{
	srand(time(NULL));
	cursor_off();
}

void gotoxy(int x, int y)  //Ŀ���� ȭ���� x��ǥ, y��ǥ�� �ű��.
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void cursor_off()  //ȭ�鿡�� Ŀ���� �����Ѵ�.
{
	CONSOLE_CURSOR_INFO Coff = { 100,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Coff);
}

char get_alphabet() // ������ ���� �Լ�
{
	int x, y;
	char alpha;
	do {
		x = rand() % 80;  //x��ǥ ����
		y = rand() % 24;  //y��ǥ ����
	} while (check_node(x,y) ==1 );  // ȭ�� x,y��ǥ�� ���ڰ� �ִٸ� �ٽ� ����
	alpha = (rand() % 26) + 'A';  //A���� Z���� ���ڸ� �ϳ� �����Ѵ�
	
	temp = (struct ALPAH_NODE*)malloc(sizeof(struct ALPHA_NODE));
	temp->x = x;
	temp->y = y;
	temp->alpha = alpha;
	
	temp->next = alphalist;
	alphalist = temp;
	return alpha;   // ������ ���ڸ� �����Ѵ�
}

void display_screen() // ������ ȭ�� ǥ�� �Լ�
{
	struct ALPHA_NODE *search = alphalist;
	while (search != NULL)
	{
		gotoxy(search->x, search->y);
		putch(search -> alpha);
		search = search->next;
	}

}
void clear_screen()
{
	struct ALPHA_NODE *search = alphalist;
	while (search != NULL)
	{
		gotoxy(search->x, search->y);
		putch(' ');
		search = search->next;
	}
}

void sleep(long wait)  //�ð������Լ�
{
	clock_t goal;
	goal = wait + clock();  //��ǥ�ð��� ����ð� +�����ð����� ����
	while (goal > clock()); //����ð��� ��ǥ�ð��� ������ ������ ����Ѵ�.
}


void play_game()  // ���� ���� �����Լ�
{
	int score;  // ���� ����� ���� int�� ���� �߰�
	char keyin, alphabet;  // ���� �����߰�

	score = 0;  // ���� �ʱ�ȭ
	clear_array();  // screen �迭 �ʱ�ȭ
	do {
		clear_screen();  //ȭ���� �����
		sleep(1000); // 1�ʰ� ����Ѵ�.
		alphabet = get_alphabet();  // ������ �����ڸ� ����
		display_screen();  // ȭ�鿡 ���
		keyin = _getch();  // �����ڸ� �Է¹޴´�.
		keyin = toupper(keyin);  // �����ڸ� �빮�ڷ� ��ȯ
		if (keyin == alphabet);
		{
			score += 1;  // ������ ������Ŵ
			gotoxy(7, 24); //����ǥ�� ��ġ�� Ŀ���� �ű�
			printf("%2d", score);  // ������ ǥ��
		}
	} while (keyin == alphabet); //�Է°��� ������ �ݺ��Ѵ�.
	clear_screen();
}

void clear_list()
{
	struct ALPHA_NODE *temp = alphalist;

	while (alphalist != NULL)
	{
		alphalist = alphalist -> next;
		free(temp);
		temp = alphalist;
	}
}

int check_node(int x, int y)
{
	struct ALPHA_NODE *search = alphalist;
	while (search != NULL)
	{
		if ((search->x == x) && (search->y == y))
			break;
		else
			search = search->next;
	}
	return (search == NULL) ? 0 : 1;
}