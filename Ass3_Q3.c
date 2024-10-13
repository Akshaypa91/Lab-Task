#include <stdio.h>
#include <stdlib.h>

int main() {
    int month, date;
    int dayOfYear = 0;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d %d", &month, &date);

    if (month < 1 || month > 12 || date < 1 || date > daysInMonth[month - 1]) {
        printf("0\n");
        return 0;
    }

    for (int i = 0; i < month - 1; i++) {
        dayOfYear += daysInMonth[i]; 
    }
    dayOfYear += date; 
    printf("%d\n", dayOfYear);
    return 0;
}
