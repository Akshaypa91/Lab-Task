#include <stdio.h>
#define PRECISION 1e-6
#define PI 3.14159265358979323846
#define TWO_PI (2 * PI)

double cosine(double x) {
    x = x - ((int)(x / TWO_PI)) * TWO_PI;  
    
    double term = 1.0;     
    double cos_x = term;    
    double x_squared = x * x;  
    int n = 2;              
    int sign = -1;          

    while (term > PRECISION || term < -PRECISION) {
        term *= x_squared / (n * (n - 1));  
        cos_x += sign * term;  
        n += 2;                
        sign *= -1;            
    }

    return cos_x;
}

int main() {
    double x;
    scanf("%lf", &x);

    double result = cosine(x);

    printf("%.4f\n", result);

    return 0;
}
