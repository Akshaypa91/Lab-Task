#include <stdio.h>

int main() {
    int a, b, c;
    int max, min, difference;

    // Read three integers
    printf("Enter three integers: ");
    scanf("%d %d %d", &a, &b, &c);

    // Initialize max and min with the first number
    max = min = a;

    // Find maximum and minimum using a single if-else
    if (b > max) {
        max = b;
    } else {
        if (b < min) {
            min = b;
        }
    }

    if (c > max) {
        max = c;
    } else {
        if (c < min) {
            min = c;
        }
    }

    // Calculate the difference
    difference = max - min;

    // Print the result
    printf("The difference between the maximum and minimum is: %d\n", difference);

    return 0;
}
