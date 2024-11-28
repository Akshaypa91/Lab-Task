#include <stdio.h>
#include <strings.h>

int strcasecompare(char *a, char *b) {
    int result = strcasecmp(a, b);
    if (result < 0) {
        return -1;
    } else if (result > 0) {
        return 1;
    } else {
        return 0;
    }
}
