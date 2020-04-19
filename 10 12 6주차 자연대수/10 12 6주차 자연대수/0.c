#include<stdio.h>
#include<math.h>

void main()
{
	int n;
	double nexp, newexp, oldexp, fact;
	nexp = exp(1, 0);
	printf("n   자연대수   수열계산   오차\n");
	printf("=======================================\n");
	n = 1;
	newexp = 0.0;
	oldexp = 1.0;
	fact = 1.0;

	while (oldexp != newexp)
	{
		oldexp = newexp;
		newexp = newexp + 1.0 / fact;
		printf("%d  %20.18lf   %20.18lf  %20.18lf\n", n, nexp, newexp, fabs(nexp -newexp));
		fact = fact * (double)n;
		n = n + 1;
	}
}