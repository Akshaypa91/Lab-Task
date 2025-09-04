#include <stdio.h>
#include <stdlib.h>

char *inttostring(int x) {
    int max_size = 12;
    char *str = (char*)malloc(max_size);
    
    snprintf(str, max_size, "%d", x);
    return str;
}
