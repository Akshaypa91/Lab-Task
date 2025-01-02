#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int main(int argc, char *argv[])
{
	if (argc < 2) {
		fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
		return 1;
	}

	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("Error opening file");
		return 1;
	}

	char buffer[BUFFER_SIZE];
	int bytes_read;
	int char_count = 0, word_count = 0, line_count = 0;
	int in_word = 0;

	while ((bytes_read = read(fd, buffer, BUFFER_SIZE)) > 0) {
		for (int i = 0; i < bytes_read; i++) {
			char_count++;

			if (buffer[i] == '\n') {
				line_count++;
			}

			if (is_whitespace(buffer[i])) {
				if (in_word) {
					word_count++;
					in_word = 0;
				}
			} else {
				in_word = 1;
			}
		}
	}

	if (in_word) {
		word_count++;
	}

	if (bytes_read < 0) {
		perror("Error reading file");
		close(fd);
		return 1;
	}

	close(fd);

	char output[BUFFER_SIZE];
	int output_length = snprintf(output, BUFFER_SIZE, "  %d  %d  %d %s\n", line_count, word_count, char_count, argv[1]);
	write(1, output, output_length);

	return 0;
}
