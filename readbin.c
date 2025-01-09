#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <time.h>
#include <string.h>

typedef struct transaction {
    double amount;
    time_t time;
    unsigned int from_id;
    unsigned int to_id;
    char location[32];
} transaction;

void print_transaction_details(const transaction *trans) {
    char time_str[20];
    struct tm *gmt_time = gmtime(&trans->time);
    strftime(time_str, sizeof(time_str), "%d:%m:%Y %H:%M:%S", gmt_time);

    printf("%s\n", time_str);
}

int main(int argc, char *argv[]) {

    char filename[100];

	fgets(filename, sizeof(filename), stdin);

	size_t len = strlen(filename);
	if (filename[len - 1] == '\n')
		filename[len - 1] = '\0';
    int fd = open(filename, O_RDONLY);
    if (fd < 0) {
        perror("Error opening file");
        return 1;
    }

    int n;
    if (read(fd, &n, sizeof(int)) != sizeof(int)) {
        perror("Error reading number of transactions");
        close(fd);
        return 1;
    }

    if (n <= 0) {
        fprintf(stderr, "Invalid number of transactions in the file.\n");
        close(fd);
        return 1;
    }

    transaction min_trans, current_trans;
    int is_first = 1;

    for (int i = 0; i < n; i++) {
        if (read(fd, &current_trans, sizeof(transaction)) != sizeof(transaction)) {
            perror("Error reading transaction data");
            close(fd);
            return 1;
        }

        if (is_first || current_trans.amount < min_trans.amount) {
            min_trans = current_trans;
            is_first = 0;
        }
    }

    close(fd);

    print_transaction_details(&min_trans);

    return 0;
}

