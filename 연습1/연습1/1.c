#include<stdio.h>
#include<string.h>

int main()
{
	char str[] = "this#is#a#sample#string";
	char *token;

	token = strtok(str, "i");
	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, "s");
	}
	return 0;
}