#include <stdio.h>

char *strstr(char *a, char *b) {
    
    char *p1 = a;

    while (*p1) {
        char *p1_st = p1;
        char *p2 = b;

        while (*p1 && *p2 && *p1 == *p2) {
            p1++;
            p2++;
        }

        if (!*p2) {
            return p1_st;
        }

        p1 = p1_st + 1;
    }
}

int main() {
    char a[] = "abhijit is here";
    char b[] = "is";
    char *result = strstr(a, b);

    printf("%s", result);

    return 0;
}

