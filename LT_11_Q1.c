#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double *arr, sum = 0, average;

    scanf("%d", &n);

    arr = (double *)malloc(n * sizeof(double));

    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }

    average = sum / n;

    printf("%.2f\n", average);

    free(arr);

    return 0;
}
