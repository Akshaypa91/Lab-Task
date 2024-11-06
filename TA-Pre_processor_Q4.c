#include <stdio.h>
#define MAX(a,b) ((a) > (b) ? (a) : (b))
#define SQ(x) ((x) * (x))
#define DOUBLEMAX(x,y) (MAX(x,y) + MAX(x,y))

int main() {
    int i, j;
    scanf("%d%d", &i, &j);
    printf("%d\n", (SQ(DOUBLEMAX(i,j))));  // z2 where z is the 2*(maximum between i and j)
    return 0;
}
