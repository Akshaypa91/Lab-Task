#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

#define BUFFER_SIZE 1024

int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    int bytesRead;
    int charCount = 0, wordCount = 0, lineCount = 0;
    int inWord = 0;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            charCount++;

            if (buffer[i] == '\n') {
                lineCount++;
            }

            if (is_whitespace(buffer[i])) {
                if (inWord) {
                    wordCount++;
                    inWord = 0;
                }
            } else {
                inWord = 1;
            }
        }
    }

    if (inWord) {
        wordCount++;
    }

    if (bytesRead < 0) {
        perror("Error reading file");
        close(fd);
        return 1;
    }

    close(fd);

    char output[BUFFER_SIZE];
    int outputLength = snprintf(output, BUFFER_SIZE, "  %d  %d  %d %s\n", lineCount, wordCount, charCount, argv[1]);
    write(1, output, outputLength);

    return 0;
}
