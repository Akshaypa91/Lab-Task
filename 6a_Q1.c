#include <stdio.h>

int max(int a, int b){
    if (a > b) {
    return a;
} else {
    return b;
}
}

int main() {

    int n1, n2;

    while (scanf("%d %d", &n1, &n2) == 2)
    {
        printf("%d \n", max(n1, n2));
        
    }
    
    return 0;
}