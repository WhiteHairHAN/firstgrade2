#define _CRT_SECURE_NO_WARNINGS    
#include <stdio.h>
#include <string.h>

int main() {
	char str[30];
	char *save[10] = { NULL, };
	int i = 0;
	int j = 0;
	printf("�ܾ� �Է� : ");
	gets(str);
	printf("�ڸ��� �Է� : ");
	scanf("%d", &j);
	char *token = strtok(str, " ,.-");
	while (token != NULL) {
		save[i] = token;
		i++;
		token = strtok(NULL, " ,.-");
	}
	printf("%s\n", save[j]);
	return 0;
}
