#include <stdio.h>

char *stranybyte(const char *s, const char *accept) {
    
    while(*s != '\0') {
        const char *a = accept;
        while(*a != '\0') {
            if(*s == *a) {
                return (char*)s;
            }
            a++;
        }
        s++;
    }
    return NULL;
}
