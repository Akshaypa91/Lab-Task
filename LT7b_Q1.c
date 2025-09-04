#include <stdio.h>
#include <math.h>

double sqroot(double x)
{
	if (x < 0) {
		printf("Negative value Not allowed");
		return -1;
	}
return sqrt(x);
}

int main(void)
{
	double n, result;
	scanf("%lf", &n);
	result = sqroot(n);
	if (result != -1) {
		printf("%5lf", result);
	}
return 0;
}
