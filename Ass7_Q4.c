char *strchar(char *str, char c) {
    while (*str) {
        if (*str == c) {
            return str;
        }
        str++;
    }

    if (c == '\0') {
        return str;
    }

    return NULL;
}
