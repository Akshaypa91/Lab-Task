#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

#define BUFFER_SIZE 1024

int is_palindrome(const char *word, int length) {
    for (int i = 0; i < length / 2; i++) {
        if (word[i] != word[length - i - 1]) {
            return 0;
        }
    }
    return 1;
}

int is_whitespace(char c) {
    return (c == ' ' || c == '\t' || c == '\n' || c == '\r');
}

int main(int argc, char *argv[]) {
    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error File Opening");
        return 1;
    }

    char buffer[BUFFER_SIZE];
    char word[BUFFER_SIZE];
    int bytesRead, wordIndex = 0;

    while ((bytesRead = read(fd, buffer, BUFFER_SIZE)) > 0) {
        for (int i = 0; i < bytesRead; i++) {
            if (is_whitespace(buffer[i]) || buffer[i] == '\0') {
                if (wordIndex > 0) {
                    word[wordIndex] = '\0';
                    if (is_palindrome(word, wordIndex)) {
                        write(1, word, wordIndex);
                        write(1, "\n", 1);
                    }
                    wordIndex = 0;
                }
            } else {
                if (wordIndex < BUFFER_SIZE - 1) {
                    word[wordIndex++] = buffer[i];
                }
            }
        }
    }

    if (wordIndex > 0) {
        word[wordIndex] = '\0';
        if (is_palindrome(word, wordIndex)) {
            write(1, word, wordIndex);
            write(1, "\n", 1);
        }
    }

    if (bytesRead < 0) {
        perror("Error reading file");
    }

    close(fd);
    return 0;
}
