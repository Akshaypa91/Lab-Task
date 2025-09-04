#include <stdio.h>

long n_factorial(long n)
{
	long i = n, result = 1;

	while (i - 1 > 0) {
		result = result * i;
		i--;
	}
	return result;
}

double xpower_n(double x, long n)
{
	double result = x;


	while ((n - 1) > 0) {
		result = result * x;
		n--;
	}
	return result;
}

int main(void)
{
	long n;
	double x, result = 0;

	scanf("%lf%ld", &x, &n);

	result = xpower_n(x, n) / n_factorial(n);
	printf("%.2lf", result);
	return 0;
}
