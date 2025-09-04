char *strconcat(char *dest, const char *src) {
    char *a = dest;
    while(*dest) {
        dest++;
    }
    while(*src) {
        *dest = *src;
        dest++;
        src++;
    }
    *dest = '\0';
    return a;
}
