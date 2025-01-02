#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int is_palindrome(const char *word, int length)
{
	for (int i = 0; i < length / 2; i++)
		if (word[i] != word[length - i - 1])
			return 0;
	return 1;
}

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("Error File Opening");
		return 1;
	}

	char buffer[BUFFER_SIZE];
	char word[BUFFER_SIZE];
	int bytes_read, word_index = 0;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
		for (int i = 0; i < bytes_read; i++) {
			if (is_whitespace(buffer[i]) || buffer[i] == '\0') {
				if (word_index > 0) {
					word[word_index] = '\0';
					if (is_palindrome(word, word_index)) {
						write(1, word, word_index);
						write(1, "\n", 1);
					}
					word_index = 0;
				}
			} else if (word_index < BUFFER_SIZE - 1) {
				word[word_index++] = buffer[i];
			}
		}
	}

	if (word_index > 0) {
		word[word_index] = '\0';
		if (is_palindrome(word, word_index)) {
			write(1, word, word_index);
			write(1, "\n", 1);
		}
	}

	if (bytes_read < 0)
		perror("Error reading file");

	close(fd);
	return 0;
}
