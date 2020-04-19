#include<stdio.h>
#include<string.h>
#include<ctype.h>
#define MAXWORD 1000

void initialize();
void read_file();
void print_words();
void deallocate();
void convert_lower(char *str);

struct WORDCOUNT
{
	char *str;
	int count;
};

struct WORDCOUNT *words;
int nwords;

void main()
{
	intialize();
	read_file();
	print_words();
	deallocate();
}

void intialize()
{
	words = (struct WORDCOUNT *)malloc(sizeof(struct WORDCOUNT)*MAXWORD);
	memset(words, 0, sizeof(struct WORDCOUNT)*MAXWORD);
	nwords = 0;
}

void deallocate()
{
	free(words);
}

void read_file()
{
	char buffer[256];
	char *token;
	FILE *fp = fopen("programming.txt", "r");
	while (fgets(buffer, 255, fp) != NULL)
	{
		token = strtok(buffer, ",.!?\t\n");
		while (token != NULL)
		{
			convert_lower(token);
			printf("%s\n", token);
			token = strtok(NULL, ",.!?\t\n");
		}
	}
	fclose(fp);
}

void convert_lower(char *str)
{
	while (*str != NULL)
	{
		*str = tolower(*str);
		str++;
	}
}