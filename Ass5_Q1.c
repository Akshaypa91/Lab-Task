#include <stdio.h>

int isadigit(char ch) {
    if (ch >= '0' && ch <= '9') {
        return 1; 
    }
    return 0; 
}

