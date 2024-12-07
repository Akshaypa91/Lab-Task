#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    double *arr, sum = 0, average;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    arr = (double *)malloc(n * sizeof(double));
    if (arr == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter %d numbers:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%lf", &arr[i]);
        sum += arr[i];
    }

    average = sum / n;

    printf("The average is: %.2f\n", average);

    free(arr);

    return 0;
}
