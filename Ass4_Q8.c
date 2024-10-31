#include <stdio.h>
#include <limits.h> 

int main() {
    int number;
    int max = INT_MIN;  

    while (scanf("%d", &number) != EOF) {
        if (number > max) {
            max = number; 
        }
    }

    printf("%d\n", max);

    return 0;
}
