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
	char buffer[256], *pch;
	while (fgets(buffer, 255, fp) != NULL)
	{
		pch = buffer;
		while (*pch != NULL)
		{
			if (isupper(*pch))
				alphabet[*pch - 'A'] += 1;
			else if (islower(*pch))
				alphabet[*pch - 'a'] += 1;
			pch++;
		}
	}
	fclose(fp);
	printf("파일의 영문자 수 \n\n");
	for (n = 0; n < 26; n++)
		printf("%c : %d\t", n + 'A', alphabet[n]);
}