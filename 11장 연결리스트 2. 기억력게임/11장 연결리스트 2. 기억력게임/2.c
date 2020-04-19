#include<stdio.h>
#include<conio.h>  //getch 와 putch 함수 선언
#include<time.h> // time 함수선언
#include<windows.h>  // SetConsoleCursorPosition 함수선언

#define ESC 0x1b  //ESC의 아스키코드
#define ENTER 0x0d // 엔터키에 아스키코드 정의 
void initailize();  //게임 초기화 함수
void gotoxy(int, int); // 커서를 화면의 x,y좌표로 옮기는 함수 선언
void cursor_off(); // 화면에서 커서를 제거하는 함수 선언
void sleep(long wait);  //시간지연함수 선언
void clear_screen();  // 스크린 클리어 함수
void play_game();  //게임을 진행하는 함수선언
void display_screen();  // 영문자 출력함수
void clear_list();
char get_alphabet(); // 영문자 생성 함수 선언
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
	initailize(); //게임 초기화
	while (ch != ESC)
	{
		gotoxy(0, 24);  // 커서를 마지막 라인으로 옮기고, 안내문 출력
		printf("게임을 시작하려면 엔터, 종료하려면 ESC 를 누르세요");
		ch = _getch(); // 키를 입력한다.
		if (ch == ENTER)
		{
			gotoxy(0, 24);
			printf("점수 :                                               ");
			play_game();
		}
		clear_screen(); //화면을 지운다.
		sleep(1000); //1초간대기한다.
	}
	clear_list();
}

void initailize()
{
	srand(time(NULL));
	cursor_off();
}

void gotoxy(int x, int y)  //커서를 화면의 x좌표, y좌표로 옮긴다.
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void cursor_off()  //화면에서 커서를 제거한다.
{
	CONSOLE_CURSOR_INFO Coff = { 100,0 };
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &Coff);
}

char get_alphabet() // 영문자 생성 함수
{
	int x, y;
	char alpha;
	do {
		x = rand() % 80;  //x좌표 생성
		y = rand() % 24;  //y좌표 생성
	} while (check_node(x,y) ==1 );  // 화면 x,y좌표에 문자가 있다면 다시 생성
	alpha = (rand() % 26) + 'A';  //A부터 Z까지 문자를 하나 생성한다
	
	temp = (struct ALPAH_NODE*)malloc(sizeof(struct ALPHA_NODE));
	temp->x = x;
	temp->y = y;
	temp->alpha = alpha;
	
	temp->next = alphalist;
	alphalist = temp;
	return alpha;   // 생성된 문자를 반한한다
}

void display_screen() // 영문자 화면 표시 함수
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

void sleep(long wait)  //시간지연함수
{
	clock_t goal;
	goal = wait + clock();  //목표시간을 현재시간 +지연시간으로 설정
	while (goal > clock()); //현재시간이 목표시간에 도달할 때까지 대기한다.
}


void play_game()  // 게임 진행 구현함수
{
	int score;  // 점수 계산을 위한 int형 변수 추가
	char keyin, alphabet;  // 지역 변수추가

	score = 0;  // 점수 초기화
	clear_array();  // screen 배열 초기화
	do {
		clear_screen();  //화면을 지운다
		sleep(1000); // 1초간 대기한다.
		alphabet = get_alphabet();  // 임의의 영문자를 생성
		display_screen();  // 화면에 출력
		keyin = _getch();  // 영문자를 입력받는다.
		keyin = toupper(keyin);  // 영문자를 대문자로 변환
		if (keyin == alphabet);
		{
			score += 1;  // 점수를 증가시킴
			gotoxy(7, 24); //점수표시 위치로 커서를 옮김
			printf("%2d", score);  // 점수를 표시
		}
	} while (keyin == alphabet); //입력값이 같으면 반복한다.
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