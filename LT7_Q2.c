int main(void)
{
	int term, i = -1, j = 1, sum = 0, n;

	scanf("%d", &n);
	printf("1");
	while ((n - 1) > 0) {
		j += 2;
		term = i * j;
		if (term > 0)
			printf("+%d", term);
		else
			printf("%d", term);
		sum = sum + term;
		i = -1 * i;
		n--;
	}
	printf("\n%d", sum + 1);
	return 0;
}
