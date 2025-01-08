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

void print_formated_time(time_t t)
{
    char str[20];
    struct tm *tm_info;
    tm_info = localtime(&t);

    int hour = tm_info->tm_hour;

    if (hour == 0) {
        hour = 12;
    } else if (hour > 12) {
        hour -= 12;
    }

    strftime(str, sizeof(str), "%d:%m:%Y ", tm_info);
    printf("%s", str);

    printf("%02d:%02d:%02d", hour, tm_info->tm_min, tm_info->tm_sec);
}

void print_min_record(int min, transaction p[])
{
    print_formated_time(p[min].time);
}

int find_min_amount_record(transaction p[], int n)
{
    int i = 0;
    int min_amount_indx = 0;

    while (i < n) {
        if (p[i].amount < p[min_amount_indx].amount)
            min_amount_indx = i;
        i++;
    }
    return min_amount_indx;
}

transaction *read_records(int fd, int n)
{
    int i = 0;
    transaction *p = (transaction *)malloc(sizeof(transaction) * n);

    while (i < n) {
        read(fd, &p[i], sizeof(transaction));
        i++;
    }
    return p;
}

int main()
{
    char filename[100];
    int fd, min;
    int n = 0;

    scanf("%s", filename);

    fd = open(filename, O_RDONLY);
    if (fd < 1) {
        printf("Can't open the file: %s\n", filename);
        return 0;
    }

    read(fd, &n, sizeof(int));
    transaction *p = read_records(fd, n);
    min = find_min_amount_record(p, n);
    print_min_record(min, p);
    free(p);
    return 0;
}
