#include <stdio.h>
#include <limits.h>

void movetozero(int a[], int len) {
int add = 0, i = 0;

int min = INT_MAX;

while(i < len) {
if(min > a[i]) {
min = a[i];
add = i;
}
i++;
}
int temp = a[0];
a[0] = a[add];
a[add] = temp;
}
