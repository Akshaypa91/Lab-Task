#include<stdio.h>
#include<math.h>

#define PI 3.14

int main() {
    char type, calc;
    float b, h, s1, s2, s3, r;
    int result = scanf(" %c %c", &type, &calc);
    if (result != 2 || (type != 't' && type != 'r' && type != 's' && type != 'c') || (calc != 'a' && calc != 'p')) {
        printf("error\n");
        return 0;
    }
    switch (type) {
        case 't':  
            if (calc == 'a') {
                result = scanf("%f %f", &b, &h);
                if (result == 2)
                    printf("%.2f\n", (b * h) / 2); 
                else
                    printf("error\n");
            } else if (calc == 'p') {
                result = scanf("%f %f %f", &s1, &s2, &s3);
                if (result == 3)
                    printf("%.2f\n", s1 + s2 + s3);
                else
                    printf("error\n");
            } else {
                printf("error\n");
            }
            break;

        case 'r':
            result = scanf("%f %f", &b, &h);
            if (result == 2) {
                if (calc == 'a') {
                    printf("%.2f\n", b * h);
                } else if (calc == 'p') {
                    printf("%.2f\n", 2 * (b + h));
                } else {
                    printf("error\n");
                }
            } else {
                printf("error\n");
            }
            break;

        case 's':
            result = scanf("%f", &b);
            if (result == 1) {
                if (calc == 'a') {
                    printf("%.2f\n", b * b);
                } else if (calc == 'p') {
                    printf("%.2f\n", 4 * b); 
                } else {
                    printf("error\n");
                }
            } else {
                printf("error\n");
            }
            break;

        case 'c':  
            result = scanf("%f", &r);
            if (result == 1) {
                if (calc == 'a') {
                    printf("%.2f\n", PI * r * r); 
                } else if (calc == 'p') {
                    printf("%.2f\n", 2 * PI * r);
                } else {
                    printf("error\n");
                }
            } else {
                printf("error\n");
            }
            break;
        default:
            printf("error\n");
            break;
    }
    return 0;
}