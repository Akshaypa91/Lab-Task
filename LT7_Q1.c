#include <stdio.h>

int main(void)
{
	int pre = 0, curr = 1, i = 1, temp, next, num1, num2;

	scanf("%d%d", &num1, &num2);
	while (curr < 20000) {
		i++;
		next = curr + pre;
		if (num1 == next) {
			temp = i;
			pre = curr;
			curr = next;
			next = pre + curr;
			if (num2 == next)
				i++;
			break;
		}
		pre = curr;
		curr = next;
	}
	if (temp == i - 1) {
	printf("yes");
	} else {
	printf("no");
	}
	return 0;
}
