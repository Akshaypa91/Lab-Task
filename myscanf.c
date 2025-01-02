#include <string.h>
#include <stdio.h>

int atoi(char *str)
{
	int num = 0, digit = 0;
	int len = 0, check = 0, j = 0;

	for (int i = 0; str[i] != '.' && str[i] != '\0'; i++)
		len++;

	if (str[0] == '-') {
		check = 1;
		j = 1;
	}

	for (int i = j; i < len; i++) {
		if (str[i] - '0' <= '9' - '0') {
			digit = (int)(str[i] - '0');
			num = 10 * num + digit;
		} else {
			break;
		}
	}

	return check ? -1 * num : num;
}

float atof(char s[])
{
	float result = 0.0;
	int i = 0, sign = 1;
	float power_of_10 = 1.0;

	if (s[i] == '-') {
		sign = -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9' && s[i] != '.' && i < strlen(s)) {
		result = 10.0 * result + (s[i] - '0');
		i++;
	}

	if (s[i] == '.')
		i++;

	while (i < strlen(s) && s[i] != '\0' && s[i] - '0' <= '9' - '0') {
		result = result * 10.0 + (s[i] - '0');
		power_of_10 *= 10.0;
		i++;
	}

	return sign * result / power_of_10;
}

double atod(char s[])
{
	double result = 0.0;
	int i = 0, sign = 1;
	double power_of_10 = 1.0;

	if (s[i] == '-') {
		sign = -1;
		i++;
	}

	while (s[i] >= '0' && s[i] <= '9' && s[i] != '.' && i < strlen(s)) {
		result = 10.0 * result + (s[i] - '0');
		i++;
	}

	if (s[i] == '.')
		i++;

	while (i < strlen(s) && s[i] != '\0' && s[i] - '0' <= '9' - '0') {
		result = result * 10.0 + (s[i] - '0');
		power_of_10 *= 10.0;
		i++;
	}

	return sign * result / power_of_10;
}

int f_conversion(char *arg)
{
	char ch, f[30];
	int i = 0;

	while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' ') && ch - '0' <= '9' - '0')
		;
	f[i++] = ch;

	while (i < 30 && (ch = getchar()) && ch != '\t' && ch != ' ' && ch != '\n' && ch - '0' <= '9' - '0')
		f[i++] = ch;

	f[i] = '\0';

	float *p = (float *)arg;
	*p = atof(f);
	return 1;
}

int lf_conversion(char *arg)
{
	char ch, lf[310];
	int i = 0;

	while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' ') && ch - '0' <= '9' - '0')
		;
	lf[i++] = ch;

	while (i < 310 && (ch = getchar()) && ch != '\t' && ch != ' ' && ch != '\n' && ch - '0' <= '9' - '0')
		lf[i++] = ch;

	lf[i] = '\0';

	double *p = (double *)arg;
	*p = atod(lf);
	return 1;
}

int str_conversion(char *arg)
{
	char ch;
	int i = 0;

	while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' '))
		;
	arg[i++] = ch;

	while ((ch = getchar()) && ch != '\n' && ch != ' ' && ch != '\t')
		arg[i++] = ch;

	arg[i] = '\0';
	return 1;
}

int d_conversion(char *arg)
{
	char ch, d[11];
	int i = 0;

	while ((ch = getchar()) && (ch == '\t' || ch == '\n' || ch == ' ') && ch - '0' <= '9' - '0')
		;
	d[i++] = ch;

	while (i < 11 && (ch = getchar()) && ch != '\t' && ch != ' ' && ch != '\n' && ch - '0' <= '9' - '0')
		d[i++] = ch;

	d[i] = '\0';
	int *p = (int *)arg;

	*p = atoi(d);
	return 1;
}

int myscanf(char *format, void *arg)
{
	char ch1, ch2;
	int i = 0, check = 0;

	while (format[i++] != '%')
		;
	if (format[i - 2] == ' ')
		check = 1;
	ch1 = format[i++];
	ch2 = format[i];
	char *p = (char *)arg;

	if (ch1 == 'l') {
		if (ch2 == 'f')
			return lf_conversion(p);
		else
			return 0;
	} else if (ch1 == 's') {
		return str_conversion(p);
	} else if (ch1 == 'c') {
		if (check) {
			while ((*p = getchar()) && (*p == '\t' || *p == '\n' || *p == ' '))
				;
			return 1;
		}
		*p = getchar();
		return 1;
	} else if (ch1 == 'd') {
		return d_conversion(p);
	} else if (ch1 == 'u') {
		return d_conversion(p);
	} else if (ch1 == 'f') {
		return f_conversion(p);
	} else {
		printf("Error\n");
	return 0;
	}
}

int main(void)
{
	int i;
	int in;
	unsigned int ui;
	float f;
	double d;
	char arr[22];
	char ch;

	myscanf("%f", &f);
	printf("%f", f);
	return 0;
}