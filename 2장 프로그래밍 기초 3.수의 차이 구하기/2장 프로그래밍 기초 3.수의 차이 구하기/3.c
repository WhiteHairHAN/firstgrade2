#include<stdio.h>
#include<math.h>
#define NUM 10
void get_data();
float calc_avgstd();
float calc_stdev(float mean);
double num[NUM];
int n;

void main()
{
	float avg, stdev;
	get_data();
	avg = calc_avgstd();
	stdev = calc_stdev(avg);
	printf("\n 평균 = %6.2lf\n", avg);
	printf("표준편차 = %6.2lf\n\n", stdev);
}

void get_data()
{
	printf("최대 10개의 실수를 입력하세요.\n");
	printf("입력을 종료하려면, 0이하의 수를 입력하세요\n\n");
	n = 0;
	while (n < 10)
	{
		printf("숫자 %d:", n + 1);
		scanf("%f", num[n]);
		if (num[n] > 0.0)
			n += 1;
		else
			break;
	}
}

float calc_avgstd()
{
	float sum, avg;
	int k;
	sum = 0.0;
	for (k = 0; k < n; k++)
		sum += num[k];
	avg = sum / (float)n;
	return avg;
}

float calc_stdev(float mean)
{
	float ssum, diff, variance, stdev;
	int k;
	ssum = 0.0;
	for (k = 0; k < n; k++)
	{
		diff = num[k] - mean;
		ssum = ssum + diff*diff;
	}
	variance = ssum / (float)n;
	stdev = (float)sqrt((double)variance);
	return stdev;
}