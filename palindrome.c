#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

void print_palindrome(char *word, int len)
{
	int i = 0;

	while (i < len)
		printf("%c", word[i++]);
	printf("\n");
}

void check_palindrome(char *word, int indx)
{
	int i = 0, len, j = 0;
	char ch1, ch2;

	len = indx;
	j = len - 1;
	if (len == 1) {
		print_palindrome(word, len);
	} else if (len == 2) {
		if (word[i] >= 'A' && word[i] <= 'Z')
			ch1 = word[i] + 32;
		else
			ch1 = word[i];
		if (word[j] >= 'A' && word[j] <= 'Z')
			ch2 = word[j] + 32;
		else
			ch2 = word[j];
		if (ch1 == ch2)
			print_palindrome(word, len);
	} else {
		int check = 0;

		while (i <= j) {
			if (word[i] >= 'A' && word[i] <= 'Z')
				ch1 = word[i] + 32;
			else
				ch1 = word[i];
			if (word[j] >= 'A' && word[j] <= 'Z')
				ch2 = word[j] + 32;
			else
				ch2 = word[j];
			check = 0;
			if (ch1 == ch2) {
				i++;
				j--;
				check = 1;
			} else {
				break;
			}
		}
		if (check)
			print_palindrome(word, len);
	}
}

void read_word(int fd, char *word)
{
	char ch;
	int i = 0, indx = 0;
	while (read(fd, &ch, 1)) {
		if (ch != ' ' && ch != '\t' && ch != '\n') {
			word[i++] = ch;
			indx++;
		} else {
			check_palindrome(word, indx);
			i = 0;
			indx = 0;
		}
	}
}

int main()
{
	int fd;
	char word[200];
	char filename[100];

	fgets(filename, sizeof(filename), stdin);

	size_t len = strlen(filename);
	if (filename[len - 1] == '\n')
		filename[len - 1] = '\0';

	fd = open(filename, O_RDONLY);
	if (fd == -1) {
		perror("Error opening the file");
		return 1;
	}

	read_word(fd, word);
	close(fd);
	return 0;
}
