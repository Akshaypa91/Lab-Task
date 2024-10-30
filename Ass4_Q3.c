#include <stdio.h>

void bin_coeff(int n) {
    long long coeff = 1; 
    
    for (int r = 0; r <= n; r++) {
        printf("%lld ", coeff);
        coeff = coeff * (n - r) / (r + 1);
    }
    printf("\n");
}

int main() {
    int n;
    scanf("%d", &n);

    bin_coeff(n);
    
    return 0;
}
