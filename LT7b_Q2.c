#include <stdio.h>

int gcd(int a, int b)
{
	while (b != 0) {
		int temp = b;
		b = a % b;
		a = temp;
	}
	return a;
}

int main(void)
{
	int a, b;
	scanf("%d %d", &a, &b);
	printf("%d", gcd(a, b));
	return 0;
}
