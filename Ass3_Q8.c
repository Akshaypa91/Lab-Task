#include <stdio.h>

int main() {
    float value;
    char unit;

    if (scanf("%f %c", &value, &unit) != 2) {
        printf("error\n");
        return 0;
    }

    float inches = 0;

    switch (unit) {
        case 'f': 
            inches = value * 12;
            break;
        case 'y':
            inches = value * 36; 
            break;
        case 'm':
            inches = value * 63360;
            break;
        default:
            printf("error\n");
            return 0;
    }

    printf("%.0f\n", inches);
    return 0;
}