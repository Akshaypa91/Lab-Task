#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define LSA 1024  // Large_Size_Array(LAS)

int main() {
    char largeArray[LSA];
    char **p;                         
    int n;

    printf("Enter the number of lines: ");
    scanf("%d", &n);

    p = (char **)calloc(n , sizeof(char *));

    getchar();

    for (int i = 0; i < n; i++) {
        printf("Enter line %d: ", i + 1);
        if (fgets(largeArray, LSA, stdin) != NULL) {
            largeArray[strcspn(largeArray, "\n")] = '\0';

            p[i] = (char *)malloc(strlen(largeArray) + 1);

            strcpy(p[i], largeArray);
        }
    }

    int maxLenInd = 0;
    for (int i = 1; i < n; i++) {
        if (strlen(p[i]) > strlen(p[maxLenInd])) {
            maxLenInd = i;
        }
    }

    printf("The longest line is: %s\n", p[maxLenInd]);

    for (int i = 0; i < n; i++) {
        free(p[i]);
    }
    free(p);

    return 0;
}