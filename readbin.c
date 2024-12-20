#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <time.h>

typedef struct transaction {
    double amount;
    time_t time;
    unsigned int from_id;
    unsigned int to_id;
    char location[32];
} transaction;

void format_time(time_t t, char *buffer) {
    struct tm *tm_info = localtime(&t);
    strftime(buffer, 20, "%d:%m:%Y %H:%M:%S", tm_info);
}

int main(int argc, char *argv[]) {
    if (argc != 2) {
        write(2, "Usage: ./readbin <filename>\n", 28);
        return 1;
    }

    int fd = open(argv[1], O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    unsigned int n;
    if (read(fd, &n, sizeof(unsigned int)) != sizeof(unsigned int)) {
        write(2, "Error reading number of records\n", 32);
        close(fd);
        return 1;
    }

    transaction t, min_t;
    double min_amount = __DBL_MAX__;
    char time_str[20];

    for (unsigned int i = 0; i < n; i++) {
        if (read(fd, &t, sizeof(transaction)) != sizeof(transaction)) {
            write(2, "Error reading record\n", 21);
            close(fd);
            return 1;
        }
        if (t.amount < min_amount) {
            min_amount = t.amount;
            min_t = t;
        }
    }

    close(fd);

    format_time(min_t.time, time_str);

    dprintf(1, "Location: %s\n", min_t.location);
    dprintf(1, "Time: %s\n", time_str);

    return 0;
}
