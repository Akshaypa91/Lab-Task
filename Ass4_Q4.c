#include <stdio.h>
#include <math.h>

double fact(int n) {
    double fact = 1.0;
    for (int i = 1; i <= n; i++) {
        fact *= i;
    }
    return fact;
}

int main() {
    double x;
    int n;

    scanf("%lf %d", &x, &n);

    double x_power_n = pow(x, n);
 
    double n_fact = fact(n);
    double result = x_power_n / n_fact;
    printf("%.2f\n", result);

    return 0;
}
