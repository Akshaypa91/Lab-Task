#include <stdio.h>

int main() {
    int n;

    scanf("%d", &n);
    if (n <= 0) {
        printf("0.0000\n");
        return 0;
    }

    int sum = 0;
    int value;

    for (int i = 0; i < n; i++) {
        scanf("%d", &value);
        sum += value;
    }
    double average = (double)sum / n;
    printf("%.4f\n", average);

    return 0;
}
