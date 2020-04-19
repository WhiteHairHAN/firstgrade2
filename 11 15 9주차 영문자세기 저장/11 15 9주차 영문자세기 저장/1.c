#include<stdio.h>
#include<string.h>

void main()
{
	int i = 0;
	FILE *read_fp;
	FILE *write_fp;

	char input[100];
	int cnt[5] = { 0 };

	read_fp = fopen("입력 파일.txt", "r+");

	fgets(input, 100, read_fp);

	for (i; i < strlen(input); i++)
	{
		if (input[i] == 'a' || input[i] == 'a')
			cnt[0] ++ ;
		else if (input[i] == 'e' || input[i] == 'e')
			cnt[1] ++;
		else if (input[i] == 'i' || input[i] == 'i')
			cnt[2] ++;
		else if (input[i] == 'o' || input[i] == 'o')
			cnt[3] ++;
		else if (input[i] == 'u' || input[i] == 'u')
			cnt[4] ++;
		else continue;
	}

	fclose(read_fp);
	printf("a : %d  , e : %d , i : %d , o : %d , u ; %d ", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);

	write_fp = fopen("모음세기결과.txt", "w");
	fprintf(write_fp, "모음세기결과\n");
	fprintf(write_fp, "a : %d  , e : %d , i : %d , o : %d , u ; %d ", cnt[0], cnt[1], cnt[2], cnt[3], cnt[4]);
	fclose(write_fp);
}