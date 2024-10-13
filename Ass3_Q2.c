#include <stdio.h>
#include <stdlib.h>

int main() {
    int dayOfYear;
    int month = 0, date = 0;

    int daysInMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    scanf("%d", &dayOfYear);

    if (dayOfYear < 1 || dayOfYear > 365) {
        printf("invalid\n");
        return 0;
    }

    for (month = 0; month < 12; month++) {
        if (dayOfYear <= daysInMonth[month]) {
            date = dayOfYear;  
            break;
        } else {
            dayOfYear -= daysInMonth[month];  
        }
    }
    printf("%d %d\n", date, month + 1);
    return 0;
}
