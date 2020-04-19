#include<stdio.h>
#include<math.h>
#define MAX 10

void get_data();
void calc_avgstd(double *pavg, double *pstdev);

double num[MAX];
int n;

void main()
{
	double avg, stdev;
	get_data();
	calc_avgstd(&avg, &stdev);
	printf("\n ��� = %lf\n ", avg);
	printf("\n ǥ������ = %lf\n\n", stdev);
}

void get_data()
{
	printf("�ִ� 10���� �Ǽ��� �Է��ϼ��� \n");
	printf("�Է��� �����Ϸ��� , 0 ������ ���� �Է��ϼ��� \n\n");
	while (n < 10) {
		printf("���� %d : ", n + 1);
		scanf("%lf", &num[n]);
		if (num[n] > 0)
			n += 1;
		else
			break;
	}
}

void calc_avgstd(double *pavg, double *pstdev)
{
	double sum, ssum, mean, variance, std;
	int k;

	sum = ssum = 0.0;
	for (k = 0; k < n; k++)
	{
		sum += num[k];
		ssum += (num[k] * num[k]);
	}
	*pavg = sum / (double)n;
	variance = ssum / (double)n - (*pavg)*(*pavg);
	*pstdev = sqrt(variance);
}