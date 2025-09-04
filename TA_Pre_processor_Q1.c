#include <stdio.h>
#define ADD(a, b)  a + b

int main() {
    printf("%d\n", ADD(10, 20) * ADD(10, 20)); // 230
    return 0;
}
