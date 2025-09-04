#include <stdio.h>

int subtract(int a, int b) {
    if (b == 0) {
        return a;
    }
    
    return subtract(a-1, b-1);
}

int main() {
    int num1, num2;

    scanf("%d %d", &num1, &num2);

    int result = subtract(num1, num2);
    printf("%d\n", result);

    return 0;
}
