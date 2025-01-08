#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

#define MAX_LINE_LENGTH 1024

int find_longest_word_length(const char *line) {
    int max_len = 0, current_len = 0;
    for (int i = 0; line[i] != '\0'; i++) {
        if (line[i] == ' ' || line[i] == '\n' || line[i] == '\t') {
            if (current_len > max_len) {
                max_len = current_len;
            }
            current_len = 0;
        } else {
            current_len++;
        }
    }
    if (current_len > max_len) {
        max_len = current_len;
    }
    return max_len;
}

int main(int argc, char *argv[]) {
    char filename[100];

	fgets(filename, sizeof(filename), stdin);

	size_t len = strlen(filename);
	if (filename[len - 1] == '\n')
		filename[len - 1] = '\0';

	int file = open(filename, O_RDONLY);
    if (file < 0) {
        perror("Error");
        return 1;
    }

    char line[MAX_LINE_LENGTH];
    char longest_line[MAX_LINE_LENGTH] = "";
    int max_word_length = 0;
    ssize_t bytes_read;
    char buffer[MAX_LINE_LENGTH];
    int buffer_index = 0;

    while ((bytes_read = read(file, buffer + buffer_index, sizeof(buffer) - buffer_index - 1)) > 0) {
        buffer[bytes_read + buffer_index] = '\0';
        char *start = buffer;
        char *newline;

        while ((newline = strchr(start, '\n')) != NULL) {
            *newline = '\0';
            strncpy(line, start, MAX_LINE_LENGTH);
            line[MAX_LINE_LENGTH - 1] = '\0';
            int current_longest_word = find_longest_word_length(line);
            if (current_longest_word > max_word_length) {
                max_word_length = current_longest_word;
                strcpy(longest_line, line);
            }
            start = newline + 1;
        }

        buffer_index = strlen(start);
        memmove(buffer, start, buffer_index);
    }

    close(file);

    if (strlen(longest_line) > 0) {
        printf("%s\n", longest_line);
    } else {
        printf("The file is empty or contains no valid lines.\n");
    }

    return 0;
}