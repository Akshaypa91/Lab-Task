#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int is_separator(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int main(int argc, char *argv[])
{
	int fd = open(argv[1], O_RDONLY);
	if (fd < 0) {
		perror("Error opening file");
		return 1;
	}

	char buffer[BUFFER_SIZE];
	char longestWord[BUFFER_SIZE] = "";
	char currentWord[BUFFER_SIZE] = "";
	char longestLine[BUFFER_SIZE] = "";
	char currentLine[BUFFER_SIZE] = "";
	int bytesRead, wordIndex = 0, lineIndex = 0, maxWordLength = 0;

	while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
		for (int i = 0; i < bytesRead; i++) {
			currentLine[lineIndex++] = buffer[i];

			if (is_separator(buffer[i])) {
				if (wordIndex > 0) {
					currentWord[wordIndex] = '\0';
					if (strlen(currentWord) > maxWordLength) {
						maxWordLength = strlen(currentWord);
						strcpy(longestWord, currentWord);
						strcpy(longestLine, currentLine);
					}
					wordIndex = 0;
				}
				if (buffer[i] == '\n') {
					lineIndex = 0;
					currentLine[0] = '\0';
				}
			} else {
				currentWord[wordIndex++] = buffer[i];
			}
		}
	}

	if (wordIndex > 0) {
		currentWord[wordIndex] = '\0';
		if (strlen(currentWord) > maxWordLength) {
			maxWordLength = strlen(currentWord);
			strcpy(longestWord, currentWord);
			strcpy(longestLine, currentLine);
		}
	}

	if (bytesRead < 0) {
		perror("Error reading file");
		close(fd);
		return 1;
	}

	close(fd);

	write(1, longestLine, strlen(longestLine));
	return 0;
}
