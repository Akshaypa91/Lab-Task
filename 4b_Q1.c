#include <stdio.h>
#include <ctype.h>

int main() {
    char ch;
    
    while (1) {
        ch = getchar(); 

        if (ch == EOF) {
            break;
        }

        if (ch == '\n' || ch == ' ' || ch == '\t') {
            printf("not-vowel\n");
            continue; 
        }

        char lower_ch = tolower(ch);

        if (lower_ch == 'a' || lower_ch == 'e' || lower_ch == 'i' || 
            lower_ch == 'o' || lower_ch == 'u') {
            printf("vowel\n");
        } else {
            printf("not-vowel\n");
        }
    }

    return 0;
}
