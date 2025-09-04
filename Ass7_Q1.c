#include <stdio.h>
#include <string.h>


char *strdupl(const char *s){
    
    size_t length = strlen(s) + 1;
    char *duplicate = (char *)malloc(length);

    strcpy(duplicate, s);

    return duplicate;
}
