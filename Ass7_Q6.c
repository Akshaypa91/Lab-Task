#include <stdio.h>
#include <ctype.h>

long stringtoint(char *str) {
    long result = 0;
    int sign = 1;
    
    if(*str == '-') {
        sign = -1;
        str++;
    }
    
    while(*str && isdigit(*str)) {
        result = result*10 + (*str - '0');
        str++;
    }
    return sign*result;
}
