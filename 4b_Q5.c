#include <stdio.h>
#include <limits.h> 

int main() {
    int num;
    int min = INT_MAX; 
    int count = 0;

    
    while (scanf("%d", &num) != -1) {
        if (num < min) {
            min = num;  
        }
        count++;
    }

    if (count == 0) {
        
        printf("error\n");
    } else {
        
        printf("%d\n", min);
    }

    return 0;
}
