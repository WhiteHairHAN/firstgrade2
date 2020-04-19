#include<stdio.h>

int main(void)
{
	char src[] = "the boy who shattered time";
	char dst[100];
	int i;
	printf("원본문자열 = %s \n", src);
	for (i = 0; src[i] != NULL; i++)
		dst[i] = src[i];
	dst[i] = NULL;
	printf("복사된 문자열 = %s\n", dst);

	return 0;
}