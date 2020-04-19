#include<stdio.h>
#include<ctype.h>

int alphabet[26];

void main(void)
{
	char ch;
	int n;
	FILE *fp = fopen("malloc.txt", "r");
	for (n = 0; n < 26; n++)
		alphabet[n] = 0;

	while (!feof(fp))
	{
		ch = fgetc(fp);
		if (isupper(ch))
			alphabet[ch - 'A'] += 1;
		else if (islower(ch))
			alphabet[ch - 'a'] += 1;
	}

	fclose(fp);
	printf("파일의 영문자 수 \n\n");
	for (n = 0; n < 26; n++)
	{
		printf("%c : %d   ", n + 'A', alphabet[n]);
	}
	printf("\n\n");
}