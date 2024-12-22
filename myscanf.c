#include <stdio.h>
#include <stdlib.h>

int myscanf(char *format, void *arg)
{
	switch (format[1]) {
	case 'd': {
		int *p = (int *)arg;
		int i = 0;
		char in[10];

		while (i < 10) {
			in[i] = getchar();
			if ((in[i] >= '0' && in[i] <= '9') || (i == 0 && in[i] == '-'))
				i++;
			else
				break;
		}

		in[i] = '\0';
		*p = atoi(in);
		break;
	}

	default:
		break;
	}
}
