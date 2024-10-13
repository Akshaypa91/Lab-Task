#include <stdio.h>

int main() {
    char ch;
    scanf(" %c", &ch); 

    if (ch >= 'a' && ch <= 'z') {
        printf("small\n");
    } else if (ch >= 'A' && ch <= 'Z') {
        printf("capital\n");
    } else if (ch >= '0' && ch <= '9') {
        printf("digit\n");
    } else {
        printf("other\n");
    }

    return 0;
}