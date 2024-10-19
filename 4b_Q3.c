#include <stdio.h>

int main() {
    int first, last;
    int num;
    int count = 0;

    while (scanf("%d", &num) != -1) {
        if (count == 0) {
            first = num;  
        }
        last = num;  
        count++;
    }

    if (count == 0) {
        
        printf("error\n");
    } else {
        
        printf("%d\n", last - first);
    }

    return 0;
}
