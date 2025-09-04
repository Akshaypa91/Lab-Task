#include <stdio.h>

int main(void)
{
    char shape, val;
    int x;
    double base, hei, hypo;

    scanf("%c", &shape);
    switch (shape) {
        case 't':
            scanf(" %c", &val);
            if (val == 'a') {
                x = scanf("%lf%lf", &base, &hei);
                if (x <= 1)
                    printf("error");
                else
                    printf("%.2lf", 0.5 * base * hei);
            } else if (val == 'p') {
                x = scanf("%lf%lf%lf", &base, &hei, &hypo);
                if (x <= 2)
                    printf("error");
                else
                    printf("%.2lf", base + hei + hypo);
            } else {
                printf("error");
            }
            break;

        case 'r':
            scanf(" %c", &val);
            if (val == 'a') {
                x = scanf("%lf%lf", &base, &hei);
                if (x <= 1)
                    printf("error");
                else
                    printf("%.2lf", base * hei);
            } else if (val == 'p') {
                x = scanf("%lf%lf", &base, &hei);
                if (x <= 1)
                    printf("error");
                else
                    printf("%.2lf", 2 * (base + hei));
            } else {
                printf("error");
            }
            break;

        case 's':
            scanf(" %c", &val);
            if (val == 'a') {
                x = scanf("%lf", &base);
                if(x == 0){
                    printf("error");
                } else {
                 printf("%.2lf", base * base);   
                }
            } else if (val == 'p') {
                scanf("%lf", &base);
                printf("%.2lf", 4 * base);
            } else {
                printf("error");
            }
            break;

        case 'c':
            scanf(" %c", &val);
            if (val == 'a') {
                scanf("%lf", &base);
                printf("%.2lf", 3.14 * base * base);
            } else if (val == 'p') {
                scanf("%lf", &base);
                printf("%.2lf", 2 * 3.14 * base);
            } else {
                printf("error");
            }
            break;
            default :
            printf("error");
            break;
    }
    return 0;
}
